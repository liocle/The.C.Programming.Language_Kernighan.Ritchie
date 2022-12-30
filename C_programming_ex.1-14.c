//	This program prints an horizontal histogram of the frequency of each
//	printable characters in its input. 
//	The printable character range defines the size of the character
//	array.
//	Each array element corresponds to a character ordered in ascii increasing
//	order.
//	getchar() is used for the input of characters to be accounted for.
//	Once EOF (ctrl + D) is sent, the character aquisition loop stops and
//	printing starts. 
//	The character array is then checked element(character) by element. Only
//	input characters are processed, an occurence being represented by a *.
//	Printing takes place in ascii ascending order. 
//	Thank you to Faisal Saadatmand's git for inspiration regarding the printing
//	part https://github.com/fsaadatmand/The-C-Programming-Language 
//
// 	Any comments are welcome.


#include <stdio.h>
#include <unistd.h>

#define CHAR	95 //chars to account for as defined by ft_isprint

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);	
}

int	ft_putstr(char *string)
{
	while (*string)
		ft_putchar((char)*string++);
	return (0);	
}

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	return (0);
}

int	main(void)
{
	char	c;
	int		character[CHAR];
	int		ascii_value;
	int		frequency;
	
	ascii_value = 0;
	while (ascii_value < CHAR)
		character[ascii_value++] = 0;	

	while ((c = getchar()) != EOF)
	{
		if (ft_isprint(c))
			character[c-32]++;
	}
	ascii_value = 0;
	ft_putchar('\n');
	while ((ascii_value < CHAR)) 
	{
		frequency = 0;
		if (character[ascii_value] > 0)
		{
			ft_putchar(39);
			ft_putchar(ascii_value + 32);
			ft_putstr((char *)"' [");
			while (frequency < character[ascii_value]) 
			{
				ft_putchar('*');
				frequency++;
			}
			ft_putstr((char *)"]\n");
		}
		ascii_value++;	
	}
	return (0);
}
