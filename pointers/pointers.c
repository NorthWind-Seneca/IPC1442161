#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
* Reads an integer from the user and stores it in destination.
*
* destination	address of destination integer variable to write to.
* min			minimum check value
* max			maximum check value
*/
void readInt(int* destination, int min, int max);

/**
* Given the addresses of two doubles, returns the address of the double
* that holds the lesser value, or a if they're equal.
*
* a		address of first double
* b		address of secound double
* returns address of double containing lesser value.
*/
double* chooseLesser(double* a, double* b);

int main()
{
	int x = 0;
	double a, b, *c;

	printf("Please enter an integer between 0 and 50: ");
	readInt(NULL, 0, 50);	// Try with NULL
	printf("Please enter an integer between 0 and 50: ");
	readInt(0, 0, 50);		// Try with 0 (equivalent to NULL)
	printf("Please enter an integer between 0 and 50: ");
	readInt(&x, 0, 50);
	printf("You entered: %d\n", x);

	printf("Enter two doubles (A, B): ");
	scanf("%lf %lf", &a, &b);
	c = chooseLesser(&a, &b);
	if (c == &a)
	{
		printf("A is lesser\n");
	}
	if (c == &b)
	{
		printf("B is lesser\n");
	}
	printf("Enter a double to overwrite the lesser: ");
	scanf("%lf", c);
	printf("A:%lf B:%lf\n", a, b);

	printf("Enter any number to continue...\n");
	scanf("%d", &x);

	return 0;
}

void readInt(int* destination, int min, int max)
{
	int goodVal = 0;
	if (destination == NULL)	// NULL is always equal to 0
	{
		printf("Cannot write to NULL destination\n");
		return;
	}
	printf("Got address: %d\n", destination);

	while (!goodVal)
	{
		scanf("%d", destination);
		goodVal = *destination >= min && *destination <= max;
		if (goodVal == 0) // !goodVal
		{
			printf("Invalid integer, try again.\n");
		}
	}
}

double* chooseLesser(double* a, double* b)
{
	if (a == NULL)
	{
		printf("a cannot be NULL\n");
		return NULL;
	}
	if (b == NULL)
	{
		printf("b cannot be NULL\n");
		return NULL;
	}

	if (*a == *b || *a < *b)
	{
		return a;
	}

	return b;
}
