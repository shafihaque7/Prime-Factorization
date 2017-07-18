CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99
OBJECTS = bv.o sieve.o parfait.o

.PHONY: all
all: parfait

parfait: $(OBJECTS)
	$(CC) $(OBJECTS) -o parfait


bv.o: bv.c
	$(CC)  -c bv.c -o bv.o

sieve.o: sieve.c
	$(CC)  -c sieve.c -o sieve.o

parfait.o: parfait.c
	$(CC)  -c parfait.c -o parfait.o


.PHONY: clean
clean:
	rm -f $(OBJECTS) parfait 
