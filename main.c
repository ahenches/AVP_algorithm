#include "algo_tree.h"

int main()
{
	FILE *ptr = fopen("arbre1", "r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	node_t *racine = import_tree(ptr);
	fclose(ptr);
	
	print_tree(racine, 0);

	int total = add_recursive(racine);
	printf("%d\n", total);
	
	total = add_derecursivation(racine);
	printf("%d\n", total);

	total = add_profondeur(racine);
	printf("%d\n", total);
	
	return 0;
}
