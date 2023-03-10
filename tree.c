#include "tree.h"

node_t **import_tree(FILE *f)
{
	char line[MAX_CHARACTERE_BY_LINE];
	node_t **tab_node = malloc (MAX_SIZE_TREE*sizeof(node_t *));

	int tab_children[MAX_SIZE_TREE-1];
	int size_tab_children = 0;

	char delim_children[] = " ";
	tab_node[0] = malloc(sizeof(node_t)); // ligne 0 est tjrs la racine
	int index_node = 0;
	while(fgets(line, MAX_CHARACTERE_BY_LINE, f) != NULL)
	{
		line[strlen(line)-1] = '\0';
		printf("%s\n", line);
		char *res = strtok(line, ":");
		tab_node[index_node]->value = atoi(res); // Return Segfault si pas bon fichier
		res = strtok(NULL, delim_children);
		size_tab_children = 0;
		while (res != NULL)
		{
			int i_res = atoi(res);
			printf("%d\n", i_res);
			tab_children[size_tab_children] = i_res;
			tab_node[i_res] = malloc(sizeof(node_t));
			size_tab_children++;
			res = strtok(NULL, delim_children);
		}
		printf("TAILLEFILS %d\n", size_tab_children);
		tab_node[index_node]->n_children = size_tab_children;
		tab_node[index_node]->childs = malloc(size_tab_children * sizeof(node_t *));
		for (int i = 0; i < size_tab_children; i++)
		{
			tab_node[index_node]->childs[i] = tab_node[tab_children[i]];
		}
		index_node++;
	}
	printf("%d\n", tab_node[1]->value);
	return tab_node;
}

void print_tree(node_t *node, int h) // algo rec.
{
	print_node(node, h);
	h++;
	for(int i = 0; i < node->n_children; i++)
		print_tree(node->childs[i], h);
}

void print_node(node_t *node, int hauteur)
{
	for (int i = 0; i < hauteur; i++)
		printf("\t");
	printf("Node %d\n", node->value);
}
