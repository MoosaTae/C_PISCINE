/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:29:22 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/20 21:57:28 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_writestr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return ;
}

void	ft_putchar(char str)
{
	write(1, &str, 1);
}

void	ft_putnbr(int nbr)
{
	long long int	i;

	i = nbr;
	if (i < 0)
	{
		i *= -1;
	}
	if (i < 10)
	{
		ft_putchar(i + '0');
	}
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str)
	{
		ft_writestr((*par).str);
		write(1, "\n", 1);
		ft_putnbr((*par).size);
		write(1, "\n", 1);
		ft_writestr((*par).copy);
		write(1, "\n", 1);
		par++;
	}
}
