#include "tree.h"

typedef struct call_context_s {
	int index_in_children; // se rappeler sur quels enfants reprendre les appels 
	node_t *actual_node;
	int total_node;
} call_context_t;

call_context_t *create_context(int, node_t *, int);
void get_context(call_context_t *, int *, node_t **, int *);

typedef struct stack_s {
	int stack_size;
	call_context_t *call_contexts[MAX_SIZE_TREE]; // il n'y a pas plus d'appel que la taille de l'arbre
} stack_t;

stack_t *init_stack();
void push(stack_t *, call_context_t *);
call_context_t *pop(stack_t *); 
int stack_size(stack_t *);

typedef struct trivial_stack_s {
	int trivial_stack_size;
	node_t *nodes[MAX_SIZE_TREE]; // il n'y a pas plus d'appel que la taille de l'arbre
} trivial_stack_t;

trivial_stack_t *init_stack_tr();
void push_tr(trivial_stack_t *, node_t *);
node_t *pop_tr(trivial_stack_t *); 
int stack_size_tr(trivial_stack_t *);
