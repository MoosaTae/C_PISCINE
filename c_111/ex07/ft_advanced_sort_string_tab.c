/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:17:59 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/28 00:16:40 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (tab[j + 1] && (*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int		ft_strcmp(char *s1, char *s2)
// {
// 	while (*s1 != '\0' && (*s1 == *s2))
// 	{
// 		s1++;
// 		s2++;
// 	}
// 	return (*(unsigned char*)s1 - *(unsigned char*)s2);
// }

// int		main(void)
// {
// 	int		index;
// 	char	**tab;

// 	tab = malloc(8 * sizeof(char *));
// 	tab[0] = strdup("Hello");
// 	tab[1] = strdup("friend");
// 	tab[2] = strdup("good");
// 	tab[3] = strdup("luck");
// 	tab[4] = strdup("in");
// 	tab[5] = strdup("your");
// 	tab[6] = strdup("piscine");
// 	tab[7] = 0;
// 	index = 0;
// 	while (tab[index])
// 	{
// 		printf("tab[%d] <@ %p> = $%s$\n", index, tab + index, tab[index]);
// 		index++;
// 	}
// 	ft_advanced_sort_string_tab(tab, &ft_strcmp);
// 	printf("\n");
// 	index = 0;
// 	while (tab[index])
// 	{
// 		printf("tab[%d] <@ %p> = $%s$\n", index, tab + index, tab[index]);
// 		index++;
// 	}
// }