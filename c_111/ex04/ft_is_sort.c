/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:25:38 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/27 23:55:38 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sort;

	i = 0;
	sort = 1;
	while (i + 1 < length && sort)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			sort = 0;
		i++;
	}
	if (!sort)
	{
		i = 0;
		sort = 1;
		while (i + 1 < length && sort)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
