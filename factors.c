#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
 * gcd - Computes the greatest common divisor of two numbers.
 * @a: The first number.
 * @b: The second number.
 * Return: The greatest common divisor of a and b.
 */
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

/**
 * pollards_rho - Performs Pollard's rho algorithm for factorization.
 * @n: The number to factorize.
 * Return: A non-trivial factor of n.
 */
int pollards_rho(int n)
{
	int x = 2, y = 2, d = 1;

	while (d == 1)
	{
		x = (1LL * x * x + 1) % n;
		y = (1LL * y * y + 1) % n;
		y = (1LL * y * y + 1) % n;
		d = gcd(abs(x - y), n);
	}

	return d;
}

/**
 * factorize - Performs factorization using Pollard's rho algorithm.
 * @n: The number to factorize.
 * Return: None.
 */
void factorize(int n)
{
	if (is_prime(n))
	{
		printf("Number %d is prime.\n", n);
		return;
	}

	int p = pollards_rho(n);
	int q = n / p;

	printf("%d=%d*%d\n", n, p, q);
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

