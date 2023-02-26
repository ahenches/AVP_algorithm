#include "stack.h"

call_context_t *create_context(int index_child, node_t *actual_node, int total_node)
{
	call_context_t *cs = malloc(sizeof(call_context_t)); 
	cs->index_in_children = index_child;
	cs->actual_node = actual_node;
	cs->total_node = total_node;
	return cs;
}

void get_context(call_context_t *cs, int *get_index, node_t **get_node, int *get_total)
{
	*get_index = cs->index_in_children;
	*get_node = cs->actual_node;
	*get_total = cs->total_node;
	// free(cs);
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


trivial_stack_t *init_stack_tr()
{
	trivial_stack_t *trivial_stack = malloc(sizeof(trivial_stack));
	trivial_stack->trivial_stack_size = 0;
	return trivial_stack;
}

void push_tr(trivial_stack_t *trivial_stack, node_t *node)
{
	trivial_stack->nodes[trivial_stack->trivial_stack_size] = node;
	trivial_stack->trivial_stack_size++;
}

node_t *pop_tr(trivial_stack_t *trivial_stack)
{
	if (trivial_stack->trivial_stack_size <= 0)
		return NULL;
	return trivial_stack->nodes[--trivial_stack->trivial_stack_size];
}

int stack_size_tr(trivial_stack_t *trivial_stack)
{
	return trivial_stack->trivial_stack_size;
}
