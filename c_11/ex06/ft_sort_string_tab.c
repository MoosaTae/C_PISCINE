/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:11:01 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/27 21:34:32 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		k;
	int		size;

	size = 0;
	while (tab[size])
		size++;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			k = 0;
			while (tab[i][k] == tab[j][k] && tab[i][k])
				k++;
			if (tab[i][k] - tab[j][k] > 0)
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
