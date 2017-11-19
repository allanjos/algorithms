CFLAGS=-Wall -g

all: queue-test

queue-test: queue.o queue-test.o
	$(CC) queue-test.o queue.o -o queue-test

queue-test.o: queue.o queue-test.c
	$(CC) $(CFLAGS) -c queue-test.c -o queue-test.o

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c -o queue.o

clean:
	rm -f *.o
	rm -f queue-test
