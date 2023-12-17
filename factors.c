#include "main.h"

/**
 * factorize_number - function that factorizez numbers
 * @number: the number to be factorized.
 */

void factorize_number(int number)
{
	printf("%d=", number);

		while (number % 2 == 0)
			
			printf("2");
			number /= 2;

			if (number > 1)
				
				printf("*");

}

for (int i = 3; i <= sqrt(number); i += 2)
{
	while (number % i == 0)
	{
		printf("%s", i);
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
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
	exit(EXIT_FAILURE);
	}

	char *file_path = argv[1];
	factorize_file(file_path);

	return (0);
}
