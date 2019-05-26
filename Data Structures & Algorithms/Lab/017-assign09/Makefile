CC = gcc
CFLAGS = -ansi -pedantic -Wall -g  -std=c11 -I.

runcode: BST.o main.o
	$(CC) $(CFLAGS) $^ -o 017-assign09

BST.o: BST.c BST.h 
	$(CC) -c $< -o BST.o

main.o: main.c BST.h
	$(CC) -c $< -o main.o 