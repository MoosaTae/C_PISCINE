/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaolim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:14:21 by pkaolim           #+#    #+#             */
/*   Updated: 2023/06/13 22:33:45 by pkaolim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	len;

	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (*src != '\0')
	{
		dest[len] = *src;
		src++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

// int main(int argc, char **argv)
// {
// 	char dest[25] = "Test";
// 	char src[8] =  "Hiw Kao";
// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);
// 	printf("returned value: %s\n", ft_strcat(dest, src));
// 	printf("returned value: %s", strcat(dest, src));
// }