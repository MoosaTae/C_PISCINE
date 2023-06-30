/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:42:45 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/12 21:40:31 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	len_dest = 0;
	len_src = 0;
	i = 0;
	while (dest[len_dest])
		len_dest++;
	while (src[len_src])
		len_src++;
	while (src[i] && i + len_dest + 1 < size)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	if (i + len_dest < size)
		dest[len_dest + i] = '\0';
	if (size <= len_dest)
		return (size + len_src);
	return (len_dest + len_src);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[20] = "Hello";
	char str2[20] = "Hello";
	char *str3 = "World!";
	int size = 20;
	int r1 = strlcat(str, str3, size);
	int r2 = ft_strlcat(str2, str3, size);

	printf("%d\n%d\n", r1, r2);
	printf("%s\n%s", str, str2);
	return (0);
}
