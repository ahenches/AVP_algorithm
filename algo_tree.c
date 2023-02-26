#include "algo_tree.h" 

int add_profondeur(node_t *racine)
{
	queue_t *q = init_queue();
	enqueue(q, racine);
	node_t *actual;
	int total = 0;
	while(queue_size(q) > 0)
	{
		actual = dequeue(q);
		printf("total : %d ,  ajout de : %d\n", total, actual->value);
		total += actual->value;
		for(int i = 0; i < actual->n_children; i++)
			enqueue(q, actual->childs[i]);
	}
	return total;
}
int add_recursive(node_t *node)
{
	int total_node = node->value;
	print_node(node, 0);
	for(int i = 0; i < node->n_children; i++)
		total_node += add_recursive(node->childs[i]);
	return total_node;
}
int add_derecursivation(node_t *);
