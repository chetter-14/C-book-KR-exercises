#include <stdio.h>
#include <stdbool.h>

#define IN 1		/* inside a word */
#define OUT 0		/* outside a word */
#define CHARS_AMOUNT 128	/* according to the ASCII table */

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

void count_chars_frequencies()
{
	int charsFrequencies[CHARS_AMOUNT];
	for (int i = 0; i < CHARS_AMOUNT; i++)
		charsFrequencies[i] = 0;
	
	int c;
	while ((c = getchar()) != EOF)
		charsFrequencies[c]++;
	
	for (int i = 0; i < CHARS_AMOUNT; i++)
	{
		printf("%c (char) : ", (char)i);
		for (int j = 0; j < charsFrequencies[i]; j++)
			putchar('x');
		putchar('\n');
	}
}

int main()
{
	count_chars_frequencies();
	return 0;
}

