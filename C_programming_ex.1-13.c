// Write a program to print an horizontal and vertical  histogram of the
// length of words in its input.
// 
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	main(void)
{
	char	c;
	int		length;
	int		vhistogram;

	length = 0;
	while ((c = getchar()) != EOF)
	{
		length++;
		if ((c == ' ') || (c == '\t') || (c == '\n'))
		{

			vhistogram = length;
			printf("\nHorizontal histogram:\n", length); 
			while (length > 1 )
			{
				length--;
				ft_putchar('*');
			}			
			length = 0;

			printf("\nVertical histogram:\n", vhistogram); 
			while (vhistogram > 1 )
			{
				vhistogram--;
				ft_putchar('*');
				ft_putchar('\n');
			}			
			vhistogram = 0;

		ft_putchar('\n');
		}
	}
}

