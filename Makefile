all:
	$(MAKE) -C queue-c
	$(MAKE) -C tree-c

clean:
	$(MAKE) -C queue-c clean
	$(MAKE) -C tree-c clean