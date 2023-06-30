/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:14:18 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/12 21:38:00 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	const char	*str1;
	const char	*str2;

	if (!to_find[0])
		return (str);
	while (*str)
	{
		str1 = str;
		str2 = to_find;
		while (*str1 == *str2 && *str2)
		{
			str1++;
			str2++;
		}
		if (!*str2)
			return (str);
		str++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str = "Hello, world asdadsadsdaskasjjkasjsdhshja";
	char *str2 = "world";

	printf("%s\n%s", strstr(str, str2), ft_strstr( str, str2));
	return (1);
}