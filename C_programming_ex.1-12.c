// This get characters fron stdin, and prints words each on its own line.

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char c;
	
	while((c = getchar()) != EOF)
	{
		if ((c == ' ') || (c == '\t'))
			ft_putchar('\n');
		else
			ft_putchar(c);
	}	
	return (0);
}
