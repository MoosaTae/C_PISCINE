/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:20:57 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/14 20:41:22 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	(*diagornal_update(int table[][11], int qrow, int qcol, int d[][2]))[11]
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	while (++k < 4)
	{
		i = 0;
		while (++i < 10)
		{
			if (qrow + d[k][0] * i < 1 || qcol + d[k][1] * i < 1)
				break ;
			if (qrow + d[k][0] * i > 10 || qcol + d[k][1] * i > 10)
				break ;
			table[qrow + d[k][0] * i][qcol + d[k][1] * i] = 1;
		}
	}
	return (table);
}

int	(*update(int table[][11], int qrow, int qcol))[11]
{
	int	i;
	int	j;
	int	k;
	int	d[4][2];

	i = 0;
	j = 0;
	while (++i <= 10)
	{
		table[qrow][i] = 1;
		table[i][qcol] = 1;
	}
	d[0][0] = 1;
	d[0][1] = 1;
	d[1][0] = 1;
	d[1][1] = -1;
	d[2][0] = -1;
	d[2][1] = 1;
	d[3][0] = -1;
	d[3][1] = -1;
	return (diagornal_update(table, qrow, qcol, d));
}

void	copy_array(int src[11][11], int dest[11][11])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i <= 10)
	{
		while (++j <= 10)
			dest[i][j] = src[i][j];
		j = 0;
	}
}

int	solve(int table[][11], int idx, int pos[][2], int cnt)
{
	int	i;
	int	j;
	int	tmp[11][11];

	cnt = 0;
	if (idx == 10)
	{
		while (idx--)
		{
			ft_putchar(pos[9 - idx][0]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		return ;
	}
	j = 0;
	while (++j <= 10)
	{
		i = 0;
		while (++i <= 10)
		{
			if (table[i][j] == 0)
			{
				pos[idx][0] = i + 47;
				pos[idx][1] = j + 47;
				copy_array(table, tmp);
				cnt += solve(update(table, i, j), idx + 1, pos);
				copy_array(tmp, table);
				pos[idx][0] = -1;
				pos[idx][1] = -1;
			}
		}
	}
	return (cnt);
}

void	ft_ten_queens_puzzle(void)
{
	int	table[11][11];
	int	pos[11][2];
	int	i;
	int	j;

	i = 0;
	pos[0][0] = -1;
	pos[0][1] = -1;
	while (++i < 11)
	{
		j = 0;
		pos[i][0] = -1;
		pos[i][1] = -1;
		while (++j < 11)
			table[i][j] = 0;
	}
	return (solve(table, 0, pos));
}


	// i = 0;
	// j = 0;
	// while (++i <= 10)
	// {
	// 	j = 0;
	// 	while (++j <= 10)
	// 	{
	// 		printf("%d ", table[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("idx: %d\n", idx);

int	main(void)
{
	ft_ten_queens_puzzle();
	return (1);
}
