FLAGS=-Wall -g
CC=gcc



programme: main.c tree.c algo_tree.c queue.c
	$(CC) $(FLAGS) -o $@ $^ 
