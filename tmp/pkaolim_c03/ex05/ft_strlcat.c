/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:53:19 by pkaolim           #+#    #+#             */
/*   Updated: 2023/06/15 11:08:16 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (*src != '\0' && i < size -1)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (i);
}	

// int main()
// {
// 	unsigned int size = 10;
// 	char dest1[] = "Hello";
// 	char src1[20] = "Patrick Spongebob";

// 	// ft_strlcat(dest1, src1, size);
// 	// printf("src: %s\n", src1);
// 	// printf("dest: %s\n", dest1);
// 	// printf("returned value: %d", ft_strlcat(dest1, src1, size));

// 	strlcat(dest1, src1, size);
// 	printf("src: %s\n", src1);
// 	printf("dest: %s\n", dest1);
// 	printf("returned value:");
// }
