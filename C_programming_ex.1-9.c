#include <stdio.h>
#include <unistd.h>

void	main(void)
{
	char	c;

	c = getchar();
	while (c != EOF)
	{
		if (c == ' ')
		{
			if (c != '\n')
				write(1, &c, 1);		
			while ( c == ' ')
				c = getchar();
		}
		if (c != '\n')
			write(1, &c, 1);		
		c = getchar();
	}	
	printf("\nCharacters were all printed besides consecutive spaces which have been concatenated to a single space ' '\n");
}
