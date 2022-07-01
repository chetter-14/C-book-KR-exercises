#include <stdio.h>
#include <stdbool.h>

void charCount()
{
	double nc;
	
	for (nc = 0; getchar() != EOF; nc++)
		;
	printf("%.0f\n", nc);
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

int main()
{
	replaceMultBlanksBySingle();
	return 0;
}

