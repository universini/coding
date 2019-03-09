#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define QUEUE_SIZE	5
#define HASH_SIZE	8

typedef struct q_node_s {
	struct q_node_s	*next;
	struct q_node_s	*prev;
	int q_item;
} q_node_t;

typedef struct q_s {
	q_node_t *front;
	q_node_t *rear;
	int q_size;
	int q_count;
} q_t;

typedef struct hash_s {
	q_node_t **q_nodes;
	int hash_items;
} hash_t;

int is_q_empty(q_t *q)
{
	return(q->front == NULL &&
	q->rear == NULL);
}

int is_q_full(q_t *q)
{
	return(q->q_size == q->q_count);
}

void print_queue(q_t *q)
{
	q_node_t *qn = q->front;

	while(qn != q->rear) {
		printf("%d ", qn->q_item);
		qn = qn->next;
	}

	printf("%d\n", qn->q_item);
}

hash_t *create_hash_table(void)
{
	hash_t *h;

	h = (hash_t *) malloc(sizeof(hash_t));
	h->q_nodes = (q_node_t **) malloc(HASH_SIZE * sizeof(q_node_t));

	h->hash_items = HASH_SIZE;
	for (int i = 0; i < HASH_SIZE; i++) {
		h->q_nodes[i] = NULL;
	}

	return(h);
}

q_t *create_q(void)
{
	q_t *q;

	q = (q_t *) malloc(sizeof(q_t));
	if (q) {
		q->front = NULL;
		q->rear = NULL;
		q->q_size = QUEUE_SIZE;
	}

	return(q);
}

q_node_t *get_q_node(int q_item)
{
	q_node_t *qn;

	qn = (q_node_t *) malloc(sizeof(q_node_t));
	if (qn != NULL) {
		qn->prev = NULL;
		qn->next = NULL;
		qn->q_item = q_item;
	}

	return(qn);
}

void remove_item(q_t **q)
{
	q_node_t *qn;

	if (is_q_empty(*q)) {
		return;
	}

	qn = (*q)->rear;

	if ((*q)->front == (*q)->rear) {
		(*q)->front = NULL;
		(*q)->rear = NULL;
		goto free_node;
	}
	
	(*q)->rear = qn->prev;
	qn->prev->next = NULL;
	qn->prev = NULL;

free_node:

	free(qn);

	(*q)->q_count--;

	return;
}

void insert_item(hash_t **h, q_t **q, int q_item)
{
	q_node_t *qn;

	if (is_q_full(*q)) {
		/* remove an entry from hash  & detach from queue */
		(*h)->q_nodes[(*q)->rear->q_item] = NULL;
		remove_item(q);
	}

	qn = get_q_node(q_item);
	if (qn == NULL) {
		return;
	}

	if (is_q_empty(*q)) {
		(*q)->front = (*q)->rear = qn;
	} else {
		qn->next = (*q)->front;
		(*q)->front->prev = qn;
		(*q)->front = qn;
	}

	(*h)->q_nodes[q_item] = qn;

	(*q)->q_count++;

	return;
}

void access_cache(hash_t **h, q_t **q, int q_item)
{
	q_node_t *qn = (*h)->q_nodes[q_item];

	if (qn == NULL) {
		insert_item(h, q, q_item);
	} else {
		if (qn != (*q)->front) {
			if (qn->next != NULL) {
				qn->next->prev = qn->prev;
				qn->prev->next = qn->next;
			} else {
				(*q)->rear = qn->prev;
				(*q)->rear->next = NULL;
			}

			qn->next = (*q)->front;
			qn->prev= NULL;
			qn->next->prev = qn;
			(*q)->front = qn;
		}
	}
}

int main(void)
{
	hash_t	*h = NULL;
	q_t		*q = NULL;

	h = create_hash_table();
	if (h == NULL) {
		return(0);
	}

	q = create_q();
	if (q == NULL) {
		return(0);
	}

	access_cache(&h, &q, 2);
	access_cache(&h, &q, 3);
	access_cache(&h, &q, 1);
	access_cache(&h, &q, 6);
	access_cache(&h, &q, 5);
	access_cache(&h, &q, 1);
	access_cache(&h, &q, 2);
	access_cache(&h, &q, 6);

	print_queue(q);

	return(0);
}
