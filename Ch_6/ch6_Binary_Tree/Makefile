# -*- Makefile -*-

CC = gcc
RM = del #deleting command

all: treeTest

treeTest: treeTest.o ch6_tree.o
	$(CC) -o treeTest treeTest.o ch6_tree.o

treeTest.o: treeTest.c ch6_tree.o
	$(CC) -c treeTest.c

ch6_tree.o: ch6_tree.c
	$(CC) -c ch6_tree.c

clean:
	$(RM) /f *.o treeTest.exe