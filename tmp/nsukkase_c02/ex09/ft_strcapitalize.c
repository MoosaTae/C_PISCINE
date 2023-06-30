/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsukkase <napakorn.sk@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:58:16 by nsukkase          #+#    #+#             */
/*   Updated: 2023/06/19 02:03:29 by nsukkase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;
	int	diff;

	diff = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + diff;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	str = ft_strlowcase(str);
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	while (str[i] != '\0')
	{
		if (i > 0)
		{
			if (str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+')
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] = str[i] - 32;
			}
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	char	s1[] = "advfFSfsfFSbnf4435<fJK";

	printf("%s\n", ft_strlowcase(s1));
}
*/
