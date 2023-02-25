#include "tree.h"

queue_t *init_queue()
{
	queue_t *queue = malloc(sizeof(queue));
	queue->size_store_f = 0;
	queue->index_read_f = 0;
	return queue;
}

void enqueue(queue_t *queue, node_t *node, int hauteur)
{
	queue->nodes[queue->size_store_f] = node;
	queue->hauteurs[queue->size_store_f] = hauteur;
	queue->size_store_f++;
}

node_t *dequeue(queue_t *queue, int *hauteur)
{
	if (queue->index_read_f >= queue->size_store_f)
		return NULL;
	*hauteur = queue->hauteurs[queue->index_read_f];
	return queue->nodes[queue->index_read_f++];
}

int queue_size(queue_t *queue)
{
	return queue->size_store_f - queue->index_read_f;

}
