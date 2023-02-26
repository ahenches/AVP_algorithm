FLAGS=-Wall -g
CC=gcc



programme: main.c tree.c algo_tree.c queue.c stack.c
	$(CC) $(FLAGS) -o $@ $^ 
