#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <getopt.h>
#include <strings.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <sys/time.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>

#include "my_cq.h"
#include "my_worker.h"

#define MAX_THREADS 8

/* globals */
my_global_t    *mg;
pthread_t       tid[MAX_THREADS];
pthread_mutex_t lock;
pthread_cond_t  cond;

/*
 * process_data
 */
static int
process_data (my_data_t *dp)
{
    printf ("data.a = %d data.b = %s\n", dp->a, dp->b);
    return (0);
}

/*
 * my_thread_func
 */
static void *
my_thread_func (void *arg)
{
    int        t = *(int *)arg;
    my_data_t *datap;
    int        rc;

    while (1) {
        pthread_mutex_lock (&lock);
        pthread_cond_wait (&cond, &lock);

        if (!my_cq_is_empty (&mg->data_q_head)) {
            printf ("thread [%d] sees queue depth %u\n",
                    t+1, mg->num_entries);
            datap = my_cq_first (&mg->data_q_head,
                                 my_data_t,
                                 data_q_ent);
            my_cq_remove (datap, data_q_ent);
            mg->num_entries--;

            rc = process_data (datap);
            if (rc != 0) {
                printf ("process_data() failed [rc %d]\n", rc);
            }

            free (datap);
            pthread_mutex_unlock (&lock);
            //pthread_cond_signal (&cond);
        }
    }

    return (arg);
}

/* 
 * thread_init()
 */
static void
thread_init (void)
{
    int       rc;
    int       i;

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create (&tid[i], NULL, my_thread_func, &i);
        if (rc != 0) {
            printf ("thread - %2d create() failed\n", i+1);
        }

        mg->num_threads++;

        printf ("thread - %2d create() successful\n", i+1);
    }

    sleep(1);
    pthread_cond_signal (&cond);

    return;
}

/* 
 * main_init()
 */
static void
main_init (void)
{
    my_data_t *datap;

    mg = malloc (sizeof (*mg));
    memset (mg, 0, sizeof (*mg));
    pthread_mutex_init (&lock, NULL);
    my_cq_init (&mg->data_q_head);

    datap = malloc (sizeof (*datap));
    memset (datap, 0, sizeof (my_data_t));
    datap->a = 88;
    strcpy (datap->b, "sidde");

    pthread_mutex_lock (&lock);
    my_cq_init_ent (datap, data_q_ent);
    my_cq_insert_tail (&mg->data_q_head, datap, data_q_ent);
    mg->num_entries++;

    datap = malloc (sizeof (*datap));
    memset (datap, 0, sizeof (my_data_t));
    datap->a = 99;
    strcpy (datap->b, "gowda");

    my_cq_init_ent (datap, data_q_ent);
    my_cq_insert_tail (&mg->data_q_head, datap, data_q_ent);
    pthread_mutex_unlock (&lock);
    mg->num_entries++;

    return;
}

/*
 * main 
 */
int
main (void)
{
    main_init ();

    thread_init ();
    /* wait loop */
    main_loop ();

    return (0);
}

