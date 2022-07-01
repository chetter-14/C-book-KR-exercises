#include <stdio.h>
#define MAXLINE 1000
#define LOWER_LEN_BOUND 80

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	char line[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0)
	{
		if (len > LOWER_LEN_BOUND)
			printf("%s\n", line);
		else 
			printf("Won't be printed!\n");
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

/* copy 'from' into 'to' */
void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}

