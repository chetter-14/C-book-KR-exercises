#include <stdio.h>

void charCount()
{
	double nc;
	
	for (nc = 0; getchar() != EOF; nc++)
		;
	printf("%.0f\n", nc);
}

void countLines()
{
	int c, nl;
	
	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			nl++;
	printf("%d\n", nl);	
	
}

int main()
{
	countLines();
	return 0;
}

