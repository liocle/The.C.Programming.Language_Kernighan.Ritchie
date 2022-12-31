/* 
 * Write a program to print all input lines that are longer than 80 characters*/

#include	<stdio.h>

#define		MAXLINE 		1000 /* maximum input line size */
#define		TRESHOLD		10	 /* limit used to save line, excludes \n*/
#define		MAXSAVEDLINES	1000 /* maximum saved lines over */ 
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
	while ((to[i] = from[i]) != '\n')
		i++;
	to[i] = '\0';
}

/* 
 * Print longest input line and the amount of characters \n is printed and counted.*/
int	main(void)
{
	int		len; /* current line length */
	int		i;
	char	line[MAXLINE]; /* current input line */ 
	char	saved_lines[MAXSAVEDLINES][MAXLINE]; /* array to store lines longer or equal to THRESHOLD */

	i = 0;
	while ((len = my_getline(line, MAXLINE)) > 0)
		if (len - 1 >= TRESHOLD) /* len check against TRESHOLD to save line*/
			copy(saved_lines[i++], line);
	if (i > 0) /* There is at least one line saved */
	{
		printf("\nLines longer than THRESHOLD = %d are as follow (\\n are exluded from count):\n", TRESHOLD);		
		i = 0;	
		while (*saved_lines[i] != '\0')	
			printf("Line saved #%d -> :%s:\n", i, saved_lines[i++]);
	}
	return (0);	
}
