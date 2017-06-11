CFLAGS=-Wall -g

all: queue-test queue

queue-test: queue queue-test.o
	$(CC) $(CFLAGS) -c queue-test.c -o queue-test.o
	$(CC) queue-test.o queue.o -o queue-test

queue: queue.o
	$(CC) $(CFLAGS)  -c queue.c -o queue.o

clean:
	rm -f *.o
	rm -f queue-test
