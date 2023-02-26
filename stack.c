#include "stack.h"

call_context_t *create_context(node_t *actual_node, int index_child)
{
	call_context_t *cs = malloc(sizeof(call_context_t)); 
	cs->actual_node = actual_node;
	cs->index_in_children = index_child;
	return cs;
}

void get_context(call_context_t *cs, node_t **get_node, int *get_index)
{
	*get_node = cs->actual_node;
	*get_index = cs->index_in_children;
}

stack_t *init_stack()
{
	stack_t *stack = malloc(sizeof(stack));
	stack->stack_size = 0;
	return stack;
}

void push(stack_t *stack, call_context_t *cs)
{
	stack->call_contexts[stack->stack_size] = cs;
	stack->stack_size++;
}

call_context_t *pop(stack_t *stack)
{
	if (stack->stack_size <= 0)
		return NULL;
	return stack->call_contexts[--stack->stack_size];
}

int stack_size(stack_t *stack)
{
	return stack->stack_size;

}
