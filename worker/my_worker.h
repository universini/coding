#include "my_cq.h"

#define main_loop() \
  while (1) {       \
    sleep(10);      \
  }

#define THREAD_STACK_SIZE (16 * 2048)
#define THREAD_COUNT_MAX 16
#define THREAD_NAME_LEN 32

my_cq(data_cq) data_cq_t;

typedef struct my_global_s {
  pthread_cond_t t_cond;
  pthread_mutex_t t_mutex;
  data_cq_t data_q_head;
  uint32_t num_threads;
  uint32_t num_entries;

} my_global_t;

typedef struct my_thread_s {
  pthread_t t_id;
  char t_name[THREAD_NAME_LEN];

} my_thread_t;

typedef struct my_data_s {
  int a;
  char b[32];
  data_cq_t data_q_ent;

} my_data_t;
