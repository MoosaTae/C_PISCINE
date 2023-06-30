/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsukkase <napakorn.sk@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:57:48 by nsukkase          #+#    #+#             */
/*   Updated: 2023/06/19 02:03:57 by nsukkase         ###   ########.fr       */
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
	return (str);
}
/*
int main()
{
	char	s1[] = "advfFSfsfFSbnf4435<fJK";

	printf("%s\n", ft_strlowcase(s1));
}
*/
