/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_scraper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:56:27 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/20 18:39:45 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKY_SCRAPER_H
# define SKY_SCRAPER_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
void	solve(int **board, int **state, int idx);
void	update(int **state, int row, int col, int value);
void	print_board(int **board);
int		check_row(int **board, int i);
int		check_col(int **board, int i);
int		check_height_left(int *row, int N);
int		check_height_right(int *row, int N);
int		check_height_up(int **b, int N, int i);
int		check_height_down(int **b, int N, int i);
int		check_only_lrow(int **b, int i);
int		check_height_left_range(int **b, int N, int i);
int		check_close(int **b, int i, int j, int times);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_count_num(char *str);
int		ft_check_numspc(char *str, int size);
int		ft_check_size(int nlen);
int		check_input(int size, int argc, char *argv);
int		*split_str(int size, char *argv);
void	condition1(int i, int **state, int **board, int *argv);
void	condition2(int i, int **state, int **board, int *argv);
void	condition3(int i, int **state, int **board, int *argv);
void	condition4(int i, int **state, int **board, int *argv);
void	all_condition(int **board, int **state, int *argv);
int		**init_board(int **board, int n);
void	free_board(int **state, int **board);

#endif
