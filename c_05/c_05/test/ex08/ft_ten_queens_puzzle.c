/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:20:57 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/15 00:30:31 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	update(int table[][11], int row, int col, int value)
{
	int	i;

	i = 0;
	while (++i <= 10)
	{
		table[row][i] += value;
		table[i][col] += value;
		if (row + i <= 10 && col + i <= 10)
			table[row + i][col + i] += value;
		if (row + i <= 10 && col - i >= 1)
			table[row + i][col - i] += value;
		if (row - i >= 1 && col + i <= 10)
			table[row - i][col + i] += value;
		if (row - i >= 1 && col - i >= 1)
			table[row - i][col - i] += value;
	}
}

int	solve(int table[][11], int col, int pos[])
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (col > 10)
	{
		while (++i <= 10)
			ft_putchar(pos[i] + '0');
		ft_putchar('\n');
		return (1);
	}
	i = 0;
	while (++i <= 10)
	{
		if (table[i][col] == 0)
		{
			pos[col] = i - 1;
			update(table, i, col, 1);
			cnt += solve(table, col + 1, pos);
			update(table, i, col, -1);
		}
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	table[11][11];
	int	pos[11];
	int	i;
	int	j;

	i = 0;
	pos[0] = 0;
	while (++i < 11)
	{
		j = 0;
		pos[i] = 0;
		while (++j < 11)
			table[i][j] = 0;
	}
	return (solve(table, 1, pos));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d",ft_ten_queens_puzzle());
	return (1);
}
*/