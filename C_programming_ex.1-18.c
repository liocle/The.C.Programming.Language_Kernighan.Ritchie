/* 
 * Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines */ 

#include	<stdio.h>

#define		MAXLINE 		1000 /* maximum input line size */
#define		MAXSAVEDLINES	10 /* maximum saved lines over */ 

/* 
 * my_getline reads a line into 's' and returns its length */
int my_getline(char s[], int lim)
{
	int	c;
	int	i;

	for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		s[i] = c;
	s[i] = '\0';
	return (i);
}

/* 
 * copy 'from' into 'to'; overflow is checked in my_getline, it is here assumed to
 * be big enough */
void	copy(char to[], char from[], int len)
{
	while ((from[len] == '\t') || (from[len] == ' ') || (from[len] == '\0') || (from[len] == '\n'))
	{	
		len--;
	}
	while (len >= 0)
	{		
		to[len] = from[len];
		len--;
	}
	
}

/* 
 * Print longest input line and the amount of characters \n is printed and counted.*/
int	main(void)
{
	int		len; /* current line length */
	int		i;
	int		j;
	char	line[MAXLINE]; /* current input line */ 
	char	saved_lines[MAXSAVEDLINES][MAXLINE]; /* array to store lines longer or equal to THRESHOLD */

	i = 0;
	j = 0;
	while (i < MAXSAVEDLINES)
			*saved_lines[i++] = '\0';
	i = 0;
	while ((len = my_getline(line, MAXLINE)) > 0)
	{
		if (len && (i + j < MAXSAVEDLINES))	
			copy(saved_lines[i + j], line, len);
			if (*saved_lines[i + j] == '\0')
					j--;
		i++;
	}

	if (i > 0) /* There is at least one line saved */
	{
		printf("\n___________________________________________________________________\nThe following lines have been trimmed for trailing tabs and spaces, \nempty new lines are skipped, the max amount of saved lines is:%d:\n___________________________________________________________________\n", MAXSAVEDLINES);		
		i = 0;	
		while (i < MAXSAVEDLINES) 
		{
			if (*saved_lines[i ] == '\0')
					i++;
			else if(*saved_lines[i] != '\0')
			{
				printf("Line saved #%3.d: -> :%s:\n", i + 1, saved_lines[i]);
				i++;
			}
		}
	}
	return (0);	
}
