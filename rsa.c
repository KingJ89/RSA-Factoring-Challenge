#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <number>\n", argv[0]);
		return EXIT_FAILURE;
    }

    long n = strtol(argv[1], NULL, 10);
    factorize_rsa_number(n);

    return EXIT_SUCCESS;
}

/**
 * factorize_rsa_number - Factorize an RSA number into prime factors
 * @n: The RSA number to factorize
 */
void factorize_rsa_number(long n) {
    printf("%ld=", n);

    // Check if n is a prime number
    if (is_prime(n)) {
        printf("%ld*1\n", n);
        return;
    }

    // Find prime factors of n
    for (long i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%ld", i);
            n /= i;

            if (n > 1) {
                printf("*");
            }
        }
    }

    printf("\n");
}


/**
 * is_prime - checks if number is prime
 * 2n: nomber to be checked
 * Return: 1 if prime, 0 otherwise
 */

int is_prime(int n)
{
	if (n <= 1)
	{
		return(0);
	}

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return(0);
		}
	}
	return(1);
}
