/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:55:20 by nawuttiv          #+#    #+#             */
/*   Updated: 2023/06/18 22:43:50 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_scraper.h"

int	**init_board(int **board, int n)
{
	int	**state;
	int	i;
	int	j;

	state = malloc((n + 2) * sizeof(int *));
	state[0] = malloc((n + 2) * sizeof(int));
	state[1] = malloc((n + 2) * sizeof(int));
	i = -1;
	while (++i <= n + 1)
	{
		j = -1;
		board[i] = malloc((n + 2) * sizeof(int));
		while (++j <= n + 1)
		{
			board[i][j] = 0;
			state[0][j] = 0;
			state[1][j] = 0;
		}
	}
	board[0][0] = n;
	return (state);
}

void	free_board(int **state, int **board)
{
	int	i;
	int	n;

	i = 0;
	n = board[0][0];
	while (i <= n + 1)
		free (board[i++]);
	i = 0;
	while (i <= 1)
		free (state[i++]);
	free (board);
	free(state);
}
