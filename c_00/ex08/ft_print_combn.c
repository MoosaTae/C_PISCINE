/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:58:54 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/09 17:52:55 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (++i < n)
	{
		if (tab[i - 1] >= tab[i])
		{
			return ;
		}
	}
	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i++] + '0');
	}
	if (tab[0] + n < 10)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[10];

	i = 0;
	while (i < n)
	{
		tab[i++] = 0;
	}
	while (tab[0] + n <= 10)
	{
		print_tab(tab, n);
		tab[n - 1]++;
		i = n - 1;
		while (i && n > 1)
		{
			if (tab[i] == 10)
			{
				tab[i - 1]++;
				tab[i] = 0;
			}
			i--;
		}
	}
}
