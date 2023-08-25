#include <stdio.h>
#include <stdbool.h>

/**
 * is_prime - Checks if a number is prime.
 * @n: The number to check.
 * Return: True if prime, false otherwise.
 */
bool is_prime(int n)
{
	if (n <= 1)
	{
		return false;
	}

	if (n <= 3)
	{
		return true;
	}

	if (n % 2 == 0 || n % 3 == 0)
	{
		return false;
	}

	for (int i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
		{
			return false;
		}
	}

	return true;
}

/**
 * factorize - Performs factorization or checks if prime.
 * @n: The number to factorize.
 * Return: None.
 */
void factorize(int n)
{
	int p, q;
	for (p = 2; p * p <= n; p++)
	{
		if (n % p == 0)
		{
			q = n / p;
			printf("%d=%d*%d\n", n, p, q);
			return;
		}
	}

	if (is_prime(n))
	{
		printf("Number %d is prime.\n", n);
	}
	else
	{
		printf("Number %d is not factorizable.\n", n);
	}
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
		return (1);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	int num;
	while (fscanf(file, "%d\n", &num) == 1)
	{
		factorize(num);
	}

	fclose(file);
	return (0);
}

