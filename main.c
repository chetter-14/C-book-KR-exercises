#include <stdio.h>

void charInputOutput()
{
	int c;
	
	while ((c = getchar()) != EOF)
		putchar(c);
	putchar(c);
}

int main()
{
	charInputOutput();
	return 0;
}

