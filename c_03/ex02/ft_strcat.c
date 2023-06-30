/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:33:06 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/11 13:56:04 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	l;

	i = -1;
	l = 0;
	while (dest[l])
		l++;
	while (src[++i])
		dest[l + i] = src[i];
	dest[l + i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s1[10] = "bacd";
// 	char s2[10] = "Bacd";

// 	printf("%d\n%d", ft_strcmp(s1, s2), strcmp(s1, s2));
// 	return (1);
// }