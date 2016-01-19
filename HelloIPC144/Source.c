#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Main function
int main()
{
	int i; // Declaration

	i = 5;
	scanf("%d", &i);

	printf("Hello, world! %d", i); // Executable statement - printf can print to console *something*

	scanf("%d", &i);
}
