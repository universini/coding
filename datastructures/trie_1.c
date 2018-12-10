#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define MAX_ALPHA 26

#define false 0
#define true  1

typedef struct trie_node_s {
    struct trie_node_s *children[MAX_ALPHA];
    int is_leaf_node;
	char dummy[9];
} trie_node_t;

trie_node_t *get_trie_node(void)
{
    trie_node_t *n;

    n = malloc(sizeof(trie_node_t));

    for (int i=0; i<MAX_ALPHA; i++) {
		n->children[i] = NULL;
	}

	n->is_leaf_node = false;

    return(n);
}

void insert_trie (trie_node_t *n, const char *s)
{
	trie_node_t *t = n;

	for (int i=0; i<strlen(s)-1; i++) {
		if (t->children[*(s+i) - 'a'] == 0) {
            t->children[*(s+i) - 'a'] = get_trie_node();
			t = t->children[*(s+i) - 'a'];
		}
	}

	t->is_leaf_node = true;
	strcpy(t->dummy, s);

    return;
}

trie_node_t *search_trie (trie_node_t *n, const char *s)
{
	int flag = 1;

	for (int i=0; i<strlen(s)-1; i++) {
		if (n->children[*(s+i) - 'a'] == 0) {
			return(NULL);
		} else {
			n = n->children[*(s+i) - 'a'];
		}
	}


	return(n);
}

int main (void)
{
	trie_node_t *t, *n = get_trie_node();
    char s[5][6] = {"sidde", "sidda", "gowda", "gowdre", "sini"};
	int l = sizeof(s)/sizeof(s[0]);

    for (int i=0; i<l; i++) {
        insert_trie(n, s[i]);
    }

	t = search_trie(n, "sidde");
	printf("%s: dummy: %s\n",
		   t && t->is_leaf_node ? "Found" : "Not found", t->dummy);

	t = search_trie(n, "nidde");
	printf("%s: dummy: NULL\n",
		   t && t->is_leaf_node ? "Found" : "Not found");

	t = search_trie(n, "sidda");
	printf("%s: dummy: %s\n",
		   t && t->is_leaf_node ? "Found" : "Not found", t->dummy);

    return(0);
}
