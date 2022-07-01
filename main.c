#include <stdio.h>
#include <stdbool.h>

#define IN 1		/* inside a word */
#define OUT 0		/* outside a word */

void outputOneWordPerLine()
{
	int c, state;
	
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t')
		{
			if (state == IN)
				putchar('\n');
			state = OUT;
		}
		else 
		{
			state = IN;
			putchar(c);
		}
	}
}

void print_words_length_histogram() 
{
	int c, state;
	int wordLen = 0;
	
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN)
			{
				printf(" : ");
				for ( ; wordLen != 0; wordLen--)
					putchar('x');
			}
			putchar('\n');
			state = OUT;
		}
		else 
		{
			state = IN;
			wordLen++;
			putchar(c);
		}
	}
}

int main()
{
	print_words_length_histogram();
	return 0;
}

