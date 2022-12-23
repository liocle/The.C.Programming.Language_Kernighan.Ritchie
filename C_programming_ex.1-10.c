/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_programming_ex.1-10.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:15:51 by lclerc            #+#    #+#             */
/*   Updated: 2022/11/16 13:49:40 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

char*	print(char c)
{
	if (c == '\t')
		return((char *)"\\t");
	else if (c == '\b')
		return((char *)"\\b");
	else if (c == 92)
		return((char *)"\\\\");
	else if (c == '\n')
		return((char *)"\\n");
}


int	main(void)
{
	char	backslash;
	char	backspace;
	char	tab;
	char	newline;

	backslash = 92;
	tab = '\t';
	backspace = '\b';
	newline = '\n';

	printf("Tabs turn from :%c: to :%s:\nBackspaces from :%c: into :%s:\nBackslashes from :%c: to :%s:\nand new lines from :%c: to :%c:", tab, print(tab), backspace, print(backspace), backspace, print(backslash), newline, print(newline));
	return (0);
}
