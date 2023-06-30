/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:10:38 by pvanasri          #+#    #+#             */
/*   Updated: 2023/06/18 23:22:39 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_scraper.h"

void	condition1(int i, int **state, int **board, int *argv)
{
	int	n;
	int	mul;

	n = board[0][0];
	board[0][i] = argv[i];
	if (board[0][i] == 1 && !board[1][i])
	{
		mul = 1 << (n - 1);
		if ((mul && state[0][1]) || (mul && state[1][i]))
			return ;
		board[1][i] = n;
		update(state, 1, i, mul);
	}
}

void	condition2(int i, int **state, int **board, int *argv)
{
	int	n;
	int	mul;

	n = board[0][0];
	board[n + 1][i - n] = argv[i];
	if (board[n + 1][i - n] == 1 && !board[n][i - n])
	{
		mul = 1 << (n - 1);
		if ((mul && state[0][n]) || (mul && state[1][i - n]))
			return ;
		board[n][i - n] = n;
		update(state, n, i - n, 1 << (n - 1));
	}
}

void	condition3(int i, int **state, int **board, int *argv)
{
	int	n;
	int	mul;

	n = board[0][0];
	board[i - n * 2][0] = argv[i];
	if (board[i - n * 2][0] == 1 && !board[i - n * 2][1])
	{
		mul = 1 << (n - 1);
		if ((mul && state[0][i - n * n]) || (mul && state[1][1]))
			return ;
		board[i - n * 2][1] = n;
		update(state, i - n * 2, 1, 1 << (n - 1));
	}
}

void	condition4(int i, int **state, int **board, int *argv)
{
	int	n;
	int	mul;

	n = board[0][0];
	board[i - n * 3][n + 1] = argv[i];
	if (board[i - n * 3][n + 1] == 1 && !board[i - n * 3][n])
	{
		mul = 1 << (n - 1);
		if ((mul && state[0][i - n * 3]) || (mul && state[1][n]))
			return ;
		board[i - n * 3][n] = n;
		update(state, i - n * 3, n, 1 << (n - 1));
	}
}

void	all_condition(int **board, int **state, int *argv)
{
	int	i;
	int	n;

	n = board[0][0];
	i = 0;
	while (++i <= n * 4)
	{
		if (i <= n)
		{
			condition1(i, state, board, argv);
		}
		else if (i <= 2 * n)
		{
			condition2(i, state, board, argv);
		}
		else if (i <= 3 * n)
		{
			condition3(i, state, board, argv);
		}
		else if (i <= 4 * n)
		{
			condition4(i, state, board, argv);
		}
	}
}
