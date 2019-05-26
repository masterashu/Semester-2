CC = gcc
CFLAGS = -I.
DEPS = a.h
OBJ = a.o file.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)