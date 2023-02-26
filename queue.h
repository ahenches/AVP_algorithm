#include "tree.h"

typedef struct queue_s {
	int size_store_f;
	node_t *nodes[MAX_TAILLE_TREE-1];
	int index_read_f;
} queue_t;

queue_t *init_queue();
void enqueue(queue_t *, node_t *);
node_t *dequeue(queue_t *); 
int queue_size(queue_t *);
