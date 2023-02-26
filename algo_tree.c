#include "algo_tree.h" 

int add_recursive(node_t *actual_node)
{
	int total_node = actual_node->value;
	// print_node(node, 0);
	for(int index_child = 0; index_child < actual_node->n_children; index_child++)
		total_node += add_recursive(actual_node->childs[index_child]);
	return total_node;
}

int add_derecursivation(node_t *racine)
{
	stack_t *s = init_stack();
	push(s, create_context(racine, 0));

	while(stack_size(s) != 0)
	{



	}

}

int add_profondeur(node_t *racine)
{
	queue_t *q = init_queue();
	enqueue(q, racine);
	node_t *actual;
	int total = 0;
	while(queue_size(q) > 0)
	{
		actual = dequeue(q);
		// printf("total : %d ,  ajout de : %d\n", total, actual->value);
		total += actual->value;
		for(int i = 0; i < actual->n_children; i++)
			enqueue(q, actual->childs[i]);
	}
	return total;
}

