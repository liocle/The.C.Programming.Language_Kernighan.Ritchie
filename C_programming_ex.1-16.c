/* 
 * This exercise revises the main routine from the longest-line program p.29 so
 * that it will print correctly the length of arbitrarily long input lines and
 * as much as possible of the text */

#include	<stdio.h>

#define		MAXLINE 1000 /* maximum input line size */

/* 
 * my_getline reads a line into 's' and returns its length */
int my_getline(char s[], int lim)
{
	int	c;
	int	i;

	for (i = 0; (i < lim - 2) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return (i);
}

/* 
 * copy 'from' into 'to'; overflow is checked in my_getline, it is here assumed to
 * be big enough */
void	copy(char to[], char from[])
{
	int	i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
	to[i] = '\0';
}

/* 
 * Print longest input line and the amount of characters \n is printed and counted.*/
int	main(void)
{
	int		len; /* current line length */
	int		max; /* maximum length seen so far */
	char	line[MAXLINE]; /* current input line */ 
	char	longest[MAXLINE]; /* longest line saved here */

	max = 0;
	while ((len = my_getline(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) /* there was a line */	
		printf("The longest line was :%i: characters long\nIt contained the following characters (including '\\n') :%s:\n",  max, longest);
	return (0);	
}
