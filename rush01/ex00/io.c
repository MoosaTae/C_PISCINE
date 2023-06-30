/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:46:05 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/18 22:40:45 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_scraper.h"

int	ft_atoi(char *str)
{
	int	negative;
	int	value;

	negative = 0;
	value = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			negative = !negative;
	}
	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		if (negative)
			value -= *str - '0';
		else
			value += *str - '0';
		str++;
	}
	return (value);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(int **board)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = board[0][0];
	while (++i <= n)
	{
		j = 0;
		while (++j <= n)
		{
			ft_putchar(board[i][j] + '0');
			if (j != n)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
