#include "algo_tree.h" 

int add_recursive(node_t *actual_node)
{
	int total_node = actual_node->value;
	// print_node(node, 0);
	for(int index_child = 0; index_child < actual_node->n_children; index_child++)
		total_node += add_recursive(actual_node->childs[index_child]);
	return total_node;
}

int add_trivial_derecursivation(node_t *racine)
{
	trivial_stack_t *ts = init_stack_tr();
	push_tr(ts, racine);
	int total = 0;

	node_t *actual_node;
	while(stack_size_tr(ts) > 0)
	{
		actual_node = pop_tr(ts); 
		printf("%d, actual_node->value\n", actual_node->value);
		for (int i = actual_node->n_children - 1; i >= 0 ; i--)
		{
			push_tr(ts, actual_node->childs[i]);
		}
		total += actual_node->value;
	}

	free(ts);

	return total;

}
int add_derecursivation(node_t *racine)
{
	stack_t *s = init_stack();
	push(s, create_context(0, racine, racine->value));
	int total = 0;

	int index_child;
	node_t *actual_node;
	int total_node;
	while(stack_size(s) > 0)
	{
		get_context(pop(s), &index_child, &actual_node, &total_node);
		printf("%d, index_child \t\t %d, actual_node->value \t\t %d, total_node \n", index_child, actual_node->value, total_node);
		if (index_child >= actual_node->n_children)
		{
			if (stack_size(s) > 0)
			{
				int tmp = total_node;
				get_context(pop(s), &index_child, &actual_node, &total_node);
				push(s, create_context(index_child, actual_node, total_node+tmp));
			}
			else {
				total = total_node;
			}
		}
		else	// index_child < n_children
		{
			push(s, create_context(index_child+1, actual_node, total_node));
			push(s, create_context(0, actual_node->childs[index_child], actual_node->childs[index_child]->value));
			
		}
	}
	free(s);

	return total;

}

int add_largeur(node_t *racine)
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

