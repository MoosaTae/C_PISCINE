/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaolim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:32:57 by pkaolim           #+#    #+#             */
/*   Updated: 2023/06/15 10:13:30 by pkaolim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

// int main()
// {
// 	char t1[] = "Piscine";
// 	char t2[] = "losolim";
// 	char t3[] = "";
// 	printf("%d\n", ft_strcmp(t1, t2));
// 	printf("%d\n\n", strcmp(t1, t2));

// 	printf("%d\n", ft_strcmp(t2, t3));
// 	printf("%d", strcmp(t2, t3));
// }
