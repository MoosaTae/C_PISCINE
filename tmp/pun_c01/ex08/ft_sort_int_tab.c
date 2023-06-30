/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:50:57 by pumungka          #+#    #+#             */
/*   Updated: 2023/06/14 15:10:45 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(int*a, int*b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int*tab, int size)
{
	int	n;
	int	m;

	n = 0;
	m = 0;
	while (n < size)
	{
		while (m < size)
		{
			if (tab[m] > tab[n])
			{
				swap(&tab[n], &tab[m]);
			}
			m++;
		}
		n++;
		m = n;
	}
}
