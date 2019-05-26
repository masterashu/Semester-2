# Makefile for executable adjust

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -ansi -pedantic -Wall -g  -std=c11

# ****************************************************
# Entries to bring the executable up to date

adjust-017: adjust-017.o grades-017.o
	$(CC) $(CFLAGS) -o adjust-017 adjust-017.o grades-017.o

adjust-017.o: adjust-017.c grades-017.h
	$(CC) $(CFLAGS) -c adjust-017.c

grades-017.o: grades-017.c grades-017.h
	$(CC) $(CFLAGS) -c grades-017.c