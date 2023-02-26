#ifndef TREEH
#define TREEH
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



node_t *import_tree(FILE *);
void print_tree(node_t *, int);
void print_node(node_t *, int);
#endif
