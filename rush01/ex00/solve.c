/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:48:51 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/18 23:40:54 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_scraper.h"

int	check_valid(int **b, int **state, int idx)
{
	if (idx >= b[0][0] && idx < b[0][0] * b[0][0])
	{
		if (idx % b[0][0] == 0 &&
			check_row(b, idx / b[0][0]) == 0)
			return (0);
		if (idx > b[0][0] * (b[0][0] - 1) &&
			check_col(b, idx % b[0][0]) == 0)
			return (0);
	}
	if (idx == b[0][0] * b[0][0])
	{
		if (check_row(b, idx / b[0][0])
			&& check_col(b, b[0][0]))
		{
			print_board(b);
			state[0][0] = 1;
		}
		return (0);
	}
	return (1);
}

int	check_dpc(int **state, int i, int j, int mul)
{
	if ((state[0][i] & mul) || (state[1][j] & mul))
		return (0);
	return (1);
}

int	check_extra(int **b, int i, int j, int times)
{
	if (j < b[i][0] && times > b[0][0] - b[i][0] + j)
		return (0);
	if (b[0][0] - j + 1 < b[i][b[0][0] + 1] &&
		times > b[0][0] - b[i][b[0][0] + 1] + b[0][0] - j + 1)
		return (0);
	if (i < b[0][j] && times > b[0][0] - b[0][j] + i)
		return (0);
	if (b[0][0] - i + 1 < b[b[0][0] + 1][j] &&
		times > b[0][0] - b[b[0][0] + 1][j] + b[0][0] - i + 1)
		return (0);
	return (1);
}

void	try2fill(int **b, int **state, int idx)
{
	int	i;
	int	j;
	int	mul;
	int	times;

	i = idx / b[0][0] + 1;
	j = idx % b[0][0] + 1;
	if (!b[i][j])
	{
		times = 0;
		while (++times <= b[0][0])
		{
			mul = 1 << (times - 1);
			if (check_dpc(state, i, j, mul) && check_extra(b, i, j, times))
			{
				b[i][j] = times;
				update(state, i, j, mul);
				if (check_only_lrow(b, idx / b[0][0] + 1))
					solve(b, state, idx + 1);
				b[i][j] = 0;
				update(state, i, j, -mul);
			}
		}
	}
	else
		solve(b, state, idx + 1);
}

void	solve(int **b, int **state, int idx)
{
	if (check_valid(b, state, idx) == 0 || (state[0][0]))
		return ;
	try2fill(b, state, idx);
}
