#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"


/**
 * factorize_number - Factorize a given number into a product of smaller numbers.
 * @number: The number to factorize.
 */
void factorize_number(int number)
{
	printf("%d=", number);
	
	int i;
	
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
 * factorize_file - Factorize numbers from a file and print the results.
 * @file_path: The path to the file containing numbers.
 */
void factorize_file(char *file_path)
{
	FILE *file = fopen(file_path, "r");
	
	if (file == NULL)
	{
		perror("Error opening file");
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
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: 0 on success, non-zero on failure.
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
	return 0;
}

