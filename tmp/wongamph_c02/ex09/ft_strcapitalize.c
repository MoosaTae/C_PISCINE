/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wongamph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:55:03 by wongamph          #+#    #+#             */
/*   Updated: 2023/06/14 12:32:06 by wongamph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		c;
	char	tmp;

	i = 0;
	c = 1;
	while (str[i] != '\0' )
	{
		tmp = *(str + i);
		if (c == 1 && tmp >= 'a' && tmp <= 'z')
		{
			str[i] -= 32;
		}
		else if (c == 0 && tmp >= 'A' && tmp <= 'Z')
		{
			str[i] += 32;
		}
		if (tmp < '0' || (tmp > '9' && tmp < 'A')
			|| (tmp > 'Z' && tmp < 'a') || c > 'z')
			c = 1;
		else
			c = 0;
		i++;
	}
	return (str);
}
