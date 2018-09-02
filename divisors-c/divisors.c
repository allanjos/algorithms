#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int argument = atoi(argv[1]);
    int number_current = 0;
    int sum = 0;

    printf("Number: %d\n", atoi(argv[1]));

    printf("Divisors:");

    while (number_current < argument) {
        number_current = number_current + 1;

        if (argument % number_current != 0) {
            continue;
        }

        printf(" %d", number_current);

        sum += number_current;
    }

    printf("\n");

    printf("Divisor sum: %d\n", sum);

    return 0;
}
