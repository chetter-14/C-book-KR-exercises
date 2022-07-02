#include <stdio.h>
#define MAXLINE 1000
#define LOWER_LEN_BOUND 80

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

void reverse(char s[]);

int main()
{
	int len;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0)
	{
		reverse(line);
		printf("%s\n", line);
	}
		
	return 0;
}

/* read a line into s, return the length */
int get_line(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	s[i] = '\0';
	return i;
}

void reverse(char s[])
{
	int len;
	for (len = 0; s[len] != '\0'; len++)
		;
	
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}

/* copy 'from' into 'to' */
void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}

