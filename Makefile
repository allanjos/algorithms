all:
	$(MAKE) -C queue-c
	$(MAKE) -C tree-c
	$(MAKE) -C divisors-c
	$(MAKE) -C prime-c

clean:
	$(MAKE) -C queue-c clean
	$(MAKE) -C tree-c clean
	$(MAKE) -C divisors-c clean
	$(MAKE) -C prime-c clean
