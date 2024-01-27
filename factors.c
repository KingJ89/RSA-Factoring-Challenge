#include "main.h"

/**
 * factorize_number - function that factorizez numbers
 * @number: the number to be factorized.
 */
void factorize_number(int number)
{
	int i;

	printf("%d=", number);

	while (number % 2 == 0)
	{
		printf("2");
		number /= 2;

		if (number > 1)
		{
			printf("*");
		}
	}

	for (i = 3; i <= sqrt(number); i += 2)
	{
		while (number % i == 0)
		{
			printf("%d", i);
			number /= i;

			if (number > 1)
			{
				printf("*");
			}
		}
	}
	if (number > 2)
	{
		printf("%d", number);
	}
	printf("\n");
}

/**
 * main - Entry point
 * @argc: handles arguments
 * @argv: count of arguments
 * Return: return 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char *file_path = argv[1];

	

	return (0);
}
