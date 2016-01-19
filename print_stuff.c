#include <stdio.h>

int main()
{
	int i = 0;
	float f = 3.5;
	double d = 3.14159;
	char c = 97;
	
	printf("Hello %d-  %f [%lf] ::%c::\n", i, f, d, c);
	
	c = 'b';
	printf("Hello %d-  %f [%lf] ::%c::\n", i, f, d, c);

	scanf("%d", &i);
	printf("Hello %d-  %f [%lf] ::%c::\n", i, f, d, c);

	return 0;
}
