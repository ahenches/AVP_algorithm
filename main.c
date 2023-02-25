#include "tree.h"

int main()
{
	
	node_t rac;
	rac.value = 5;
	rac.childs = malloc(sizeof(node_t *)*2);
	rac.n_children = 2;

	node_t n0;
	n0.childs = malloc(sizeof(node_t *)*2);
	n0.value = 1;
	n0.n_children = 2;
	rac.childs[0] = &n0;

	node_t n1;
	n1.n_children = 0;
	n1.value = -5;
	rac.childs[1] = &n1;

	node_t n2;
	n2.n_children = 0;
	n2.value = 6;
	n0.childs[0] = &n2;

	node_t n3;
	n3.n_children = 0;
	n3.value = 7;
	n0.childs[1] = &n3;
	
	print_tree(&rac);


	node_t *racine = import_tree("arbre1");
	
	print_tree(racine);
	

	node_t rac1;
	rac1.value = 5;
	queue_t *q = init_queue();
	enqueue(q, &rac1, 0);
	int h;
	printf("%d\n", dequeue(q, &h)->value);

	return 0;
}
