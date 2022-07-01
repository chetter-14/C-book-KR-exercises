#include <stdio.h>
#include <stdbool.h>

#define IN 1		/* inside a word */
#define OUT 0		/* outside a word */

void countLinesCharsWords()
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
			nl++;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			nw++;
		}
	}
	printf("Lines - %d, chars - %d, words - %d", nl, nc, nw);
}

void countBlanksTabsNewlines()
{
	int c;
	int nl, bl, tab;
	
	nl = 0, bl = 0, tab = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			nl++;
			continue;
		}
		if (c == '\t')
		{
			tab++;
			continue;
		}
		if (c == ' ')
		{
			bl++;
			continue;
		}
	}
	printf("Blanks - %d, tabs - %d, newlines - %d\n", bl, tab, nl);	
	
}

void replaceMultBlanksBySingle()
{
	int c;
	
	bool isLastBlank = false;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ')
		{
			isLastBlank = false;
			putchar(c);
		}
		else 
		{
			if (!isLastBlank)
			{
				putchar(c);
				isLastBlank = true;
			}
		}
		
	}
}

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

int main()
{
	outputOneWordPerLine();
	return 0;
}

