/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:43:43 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/18 23:38:50 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_scraper.h"

int	main(int argc, char **argv)
{
	int	**board;
	int	**state;
	int	n;

	if (argc != 2)
	{
		ft_putstr("Error\nYou can enter only 2 argument");
		return (0);
	}
	n = ft_check_size(ft_count_num(argv[1]));
	if (check_input(n, argc, argv[1]))
	{
		board = malloc((n + 2) * sizeof(int *));
		if (!board)
			return (0);
		state = init_board(board, n);
		all_condition(board, state, split_str(n, argv[1]));
		solve(board, state, 0);
		if (state[0][0] == 0)
			ft_putstr("Error\n");
		free_board(state, board);
	}
	return (0);
}
