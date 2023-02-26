#ifndef TREEH
#define TREEH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_TREE 30
#define MAX_CHARACTERE_BY_LINE 61

struct node_s {
	int value;

	int n_children;
	struct node_s **childs;
};
typedef struct node_s node_t;



node_t **import_tree(FILE *);
void print_tree(node_t *, int);
void print_node(node_t *, int);
#endif
