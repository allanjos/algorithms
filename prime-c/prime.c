#include <stdio.h>
#include <stdlib.h>

short is_prime(int number) {
    int number_current = 2;

    while (number_current < number) {
        if (number % number_current == 0) {
            return 0;
        }

        number_current++;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 0;
    }

    int argument = atoi(argv[1]);

    printf("Number: %d\n", atoi(argv[1]));

    int number_current = 1;

    printf("Predecessors primes:");

    while (number_current < argument) {
        number_current = number_current + 1;

        if (!is_prime(number_current)) {
            continue;
        }

        printf(" %d", number_current);

        fflush(stdout);
    }

    printf("\n");

    return 0;
}
