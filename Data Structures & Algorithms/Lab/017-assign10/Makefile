CC = gcc
CFLAGS = -I. -ansi -g -std=c11

trie: Trie.o program1.o
	$(CC) $(CFLAGS) -o $@ $^

avl: AVL.o program2.o
	$(CC) $(CFLAGS) -o $@ $^

avl.o: avl.c AVL.h
	$(CC) $(CFLAGS) -c -o $@ $<

Trie.o: Trie.c Trie.h
	$(CC) $(CFLAGS) -c -o $@ $<

program1.o: program1.c Trie.h
	$(CC) $(CFLAGS) -c -o $@ $<

program2.o: program2.c AVL.h
	$(CC) $(CFLAGS) -c -o $@ $<
