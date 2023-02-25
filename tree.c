#include "tree.h"

node_t *import_tree(char *filename)
{
	FILE *ptr;
	char line[MAX_CARACTERE_PAR_LIGNE];

	// INITIALIZE AFN
	ptr = fopen(filename, "r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	node_t *tab_node[MAX_TAILLE_TREE];

	int tab_children[MAX_TAILLE_TREE-1];
	int size_tab_children = 0;

	// Lecture du nombre d'états finals	
	char delim[] = " ";
	int index_node = 0;
	while(fgets(line, MAX_CARACTERE_PAR_LIGNE, ptr) != NULL)
	{
		printf("%s", line);
		char *res = strtok(line, delim);
		tab_node[index_node] = malloc(sizeof(node_t));
		tab_node[index_node]->value = atoi(res);
		res = strtok(NULL, delim);
		size_tab_children = 0;
		while (res != NULL)
		{
			printf("%d\n", atoi(res));
			tab_children[size_tab_children] = atoi(res);
			size_tab_children++;
			res = strtok(NULL, delim);
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
	return tab_node[0];
}

void print_tree(node_t *racine)
{
	printf("AFFICHAGE arbre\n");
	queue_t *q = init_queue();
	enqueue(q, racine, 0);
	node_t *actual;
	int hauteur;
	while(queue_size(q) > 0)
	{
		actual = dequeue(q, &hauteur);
		print_node(actual, hauteur);
		for(int i = 0; i < actual->n_children; i++)
			enqueue(q, actual->childs[i], hauteur+1);
	}
	//print_tree_rec(racine, 0);
	printf("\n");
}

void print_node(node_t *node, int hauteur)
{
	for (int i = 0; i < hauteur; i++)
		printf("\t");
	printf("Node %d\n", node->value);
}
