#include <stdio.h>
#include <math.h>

/**
 * factorize - Factorizes an integer and prints the factorization.
 * @n: The integer to factorize.
 */
void factorize(int n)
{
	int p, q;

	for (p = 2; p <= sqrt(n); p++) 
	{
		if (n % p == 0) 
		{
			q = n / p;
			printf("%d = %d * %d\n", n, p, q);
			return;
		}
	}

	printf("%d is prime\n", n);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2) 
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) 
	{
		perror("Error opening file");
		return 1;
	}

	int num;
	while (fscanf(file, "%d\n", &num) == 1) 
	{
		factorize(num);
	}

	fclose(file);
	return 0;
}

