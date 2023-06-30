/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:16:42 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/18 23:38:05 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_scraper.h"

void	update(int **state, int row, int col, int value)
{
	state[0][row] += value;
	state[1][col] += value;
}

int	check_row(int **b, int i)
{
	if (check_height_left(b[i], b[0][0]) != b[i][0])
		return (0);
	if (check_height_right(b[i], b[0][0]) != b[i][b[0][0] + 1])
		return (0);
	return (1);
}

int	check_only_lrow(int **b, int i)
{
	return (check_height_left_range(b, b[0][0], i));
}

int	check_col(int **b, int i)
{
	if (check_height_up(b, b[0][0], i) != b[0][i])
		return (0);
	if (check_height_down(b, b[0][0], i) != b[b[0][0] + 1][i])
		return (0);
	return (1);
}
