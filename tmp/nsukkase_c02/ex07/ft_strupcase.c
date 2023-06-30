/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsukkase <napakorn.sk@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:56:36 by nsukkase          #+#    #+#             */
/*   Updated: 2023/06/19 01:57:34 by nsukkase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include <stdio.h>

/*
int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_str_is_printable(char *str)
{
	while(*str)
	{
		if (*str < 32)
			return (0);
		str++;
	}
	return (1);
}
*/
char	*ft_strupcase(char *str)
{
	int	i;
	int	diff;

	diff = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - diff;
		}
		i++;
	}
	return (str);
}
/*
int main()
{
	char	s1[] = "advfFSfsfFSbnf4435<fJK";

	printf("%s\n", ft_strupcase(s1));
}
*/
