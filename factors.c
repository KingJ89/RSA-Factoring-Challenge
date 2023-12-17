#include "main.h"

/**
 * factorize_number - function that factorizez numbers
 * @number: the number to be factorized.
 */

void factorize_number(int number)
{
	printf("%d=", number);

	for (int i = 2; i <= number; i++)
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
	printf("\n");
}


/**
 * factorize_file - factorizes numbers from a file and prints the result.
 * @file_path: the path to the file containing numbers.
 */

void factorize_file(char *file_path)
{
	FILE *file = fopen(file_path, "r");
	if (file == NULL)
	{
		perror("Error opening file contact Jan");
		exit(EXIT_FAILURE);
	}

	int number;
	while (fscanf(file, "%d", &number) != EOF)
	{
		factorize_number(number);
	}

	fclose(file);
}


/**
 * main - Entry point of program.
 * @argc: the number of command line args
 * @argv: array containing command line args.
 * Return: 0on success.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: % <file>\n", argv[0]);
	exit(EXIT_FAILURE);
	}

	char *file_path = argv[1];
	factorize_file(file_path);

	return (0);
}
