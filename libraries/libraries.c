#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int a, b, c;
	srand(0);
	a = rand();
	b = rand();
	c = rand();
	printf("%d %d %d\n", a, b, c);

	srand(time(NULL));
	a = rand();
	b = rand();
	c = rand();
	printf("%d %d %d\n", a, b, c);

	scanf("%d", &a);
	return 0;
}
