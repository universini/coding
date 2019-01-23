#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASH_TABLE_SIZE 101

typedef struct hash_node_s {
	struct hash_node_s *next;
	char                name[10];
	int                 age;
} hash_node_t;

typedef struct hash_tbl_s {
	hash_node_t **buckets;
	int           count;
	int           size;
} hash_table_t;

hash_node_t *get_new_node(const char *name, const int age)
{
	hash_node_t *hn;

	hn = (hash_node_t *) malloc(sizeof(hash_node_t));
	if (hn != NULL) {
		strncpy(hn->name, name, strlen(name));
		hn->age = age;
		hn->next = NULL;
	}

	return(hn);
}

hash_table_t *create_hash_table(int size)
{
	hash_table_t *ht;

	ht = (hash_table_t *) malloc(sizeof(hash_table_t));

	ht->buckets = (hash_node_t **) malloc(size * sizeof(hash_node_t));

	for (int idx = 0; idx < size; idx++) {
		ht->buckets[idx] = NULL;
	}

	ht->count = 0;
	ht->size = size;

	return(ht);
}

unsigned int hash_function(const int key)
{
	return(key % HASH_TABLE_SIZE);
}

void dump_hash_table(hash_table_t *ht)
{
	printf("There are %d entries in hash table\n",
		   ht->count);

	for(int i = 0; i < ht->size; i++) {
		if (ht->buckets[i] != NULL) {
			printf("value: %s key: %d\n",
				  ht->buckets[i]->name,
				  ht->buckets[i]->age);
			if (ht->buckets[i]->next != NULL) {
				hash_node_t *hn = ht->buckets[i]->next;
				while (hn->next != NULL) {
					printf("\t-value: %s key: %d\n",
						   hn->name, hn->age);
					hn = hn->next;
				}
			}
		}
	}

	return;
}

char *get_value_by_key(hash_table_t **ht, int age)
{
	hash_node_t *hn = (*ht)->buckets[hash_function(age)];

	if (hn == NULL) {
		return(NULL);
	} else {
		return(hn->name);
	}
}

void insert_key_value (hash_table_t **ht, const char *name, int age)
{
	hash_node_t *hn = (*ht)->buckets[hash_function(age)];

	if ((*ht)->count > (*ht)->size) {
		return;
	}

	if (hn == NULL) {
		hn = get_new_node(name, age);
		if (hn == NULL) {
			return;
		}

		(*ht)->buckets[hash_function(age)] = hn;
		(*ht)->count++;
	} else {
		hash_node_t *htt = hn;

		if (hn == NULL) {
			htt = malloc(sizeof(hash_node_t));
			hn = htt;
		} else {
			while(htt->next != NULL) {
				htt = htt->next;
			}

			htt->next = malloc(sizeof(hash_node_t));
			htt = htt->next;
		}

		strncpy(htt->name, name, strlen(name));
		htt->age = age;
		htt->next = NULL;
	}
		
	return;
}

int main (void)
{
	hash_table_t	*ht;
	char			*s;

	ht = create_hash_table(HASH_TABLE_SIZE);
	if (ht == NULL) {
		return(0);
	}

	insert_key_value(&ht, "sidde", 30);
	insert_key_value(&ht, "siddu", 36);
	insert_key_value(&ht, "nandu", 25);
	insert_key_value(&ht, "nanda", 33);

	dump_hash_table(ht);

	s = get_value_by_key(&ht, 36);
	printf("Retrieved value: %s using key: 36\n", s ? s : "null");

	s = get_value_by_key(&ht, 39);
	printf("Retrieved value: %s using key: 39\n", s ? s : "null");

	return(0);
}

