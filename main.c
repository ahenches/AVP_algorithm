#include "algo_tree.h"

int main()
{
	FILE *ptr = fopen("arbre1", "r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	node_t **set_tree = import_tree(ptr);

	node_t *racine = *set_tree;
	fclose(ptr);
	
	print_tree(racine, 0);

	int total = add_recursive(racine);
	printf("RECURSIVE DONE : %d\n", total);

	//total = add_derecursivation_m(racine);
	//printf("%d\n", total);

	total = add_derecursivation(racine);
	printf("DERECURSIVATION DONE : %d\n", total);

	total = add_trivial_derecursivation(racine);
	printf("TRIVIAL DERECURSIVATION DONE : %d\n", total);

	total = add_largeur(racine);
	printf("PROFONDEUR DONE : %d\n", total);

	for(int i = 0; i < MAX_SIZE_TREE; i++)
		free(set_tree[i]);
	free(set_tree);
	
	return 0;
}
