#include	<stdio.h>
#include	<unistd.h>

void	main(void)
{
	int	c;
	int	nl;
	int	tab;
	int	space;
	
	nl = tab = space = 0;
	c = getchar();
	while (c != EOF)
	{
		if (c == '\n')
			nl += 1;
		else if (c == '\t')
			tab += 1;
		else if (c == ' ')
			space += 1;
		c = getchar();
	}
	printf("EOF was sent with signal :%d:\nThere was %d nl, %d tabs and %d spaces",c , nl, tab, space);
}
