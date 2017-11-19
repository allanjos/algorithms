CFLAGS=-Wall -g

all: tree-test

tree-test: tree.o tree-test.o
	$(CC) tree-test.o tree.o -o tree-test

tree-test.o: tree.o tree-test.c
	$(CC) $(CFLAGS) -c tree-test.c -o tree-test.o

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c -o tree.o

clean:
	rm -f *.o
	rm -f tree-test
