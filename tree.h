#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERE_PAR_LIGNE 100
#define MAX_TAILLE_TREE 45

struct node_s {
	int value;

	int n_children;
	struct node_s **childs;
};
typedef struct node_s node_t;

typedef struct queue_s {
	int size_store_f;
	node_t *nodes[MAX_TAILLE_TREE-1];
	int hauteurs[MAX_TAILLE_TREE-1];
	int index_read_f;
} queue_t;

queue_t *init_queue();
void enqueue(queue_t *, node_t *, int);
node_t *dequeue(queue_t *, int *);
int queue_size(queue_t *);


node_t *import_tree(FILE *);
void print_tree(node_t *, int);
void print_node(node_t *, int);

