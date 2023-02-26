#include "tree.h"

typedef struct call_context_s {
	node_t *actual_node;
	int index_in_children; // se rappeler sur quels enfants reprendre les appels 
} call_context_t;

call_context_t *create_context(node_t *, int);
void get_context(call_context_t *, node_t **, int *);

typedef struct stack_s {
	int stack_size;
	call_context_t *call_contexts[MAX_TAILLE_TREE]; // il n'y a pas plus d'appel que la taille de l'arbre
} stack_t;

stack_t *init_stack();
void push(stack_t *, call_context_t *);
call_context_t *pop(stack_t *); 
int stack_size(stack_t *);
