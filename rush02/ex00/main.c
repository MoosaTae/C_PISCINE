/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:21:20 by nnitipan          #+#    #+#             */
/*   Updated: 2023/06/26 23:06:05 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	two_arg(char *filename, char *num)
{
	int		result;
	t_Dict	*dict;
	int		size;
	int		fd;

	size = 0;
	result = ft_atoi(num);
	fd = open(filename, size);
	if (fd < 0)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	dict = readfile(filename, &size);
	if (!is_empty(num) && is_valid(num) && !is_overflow(ft_atoi(num)))
	{
		find_key(dict, result, size);
		close(fd);
		ft_putstr("\n");
	}
	else
		ft_putstr("Error\n");
	free_dict(dict, size);
}

int	is_arg_valid(int n)
{
	if (n > 3)
	{
		ft_putstr("please not input more than 2 arguments\n");
		return (0);
	}
	return (1);
}

void	show_text(int n, char *v[], int size, t_Dict *dict)
{
	long long int	result;

	result = 0;
	if (is_arg_valid(n) && n == 2)
	{
		if (!is_empty(v[1]) && is_valid(v[1]) && !is_overflow(ft_atoi(v[1])))
		{
			result = ft_atoi(v[1]);
			if (result == 0)
			{
				find_value(result, dict);
				return ;
			}
			else
			{
				find_key(dict, result, size);
				ft_putstr("\n");
			}
		}
		else
			ft_putstr("Error\n");
	}
}

int	main(int n, char *v[])
{
	t_Dict				*dict;
	int					size;
	char				num[FIXED_SIZE];

	size = 0;
	dict = readfile("numbers.dict", &size);
	if (!dict)
		ft_putstr("Dict Error\n");
	else if (n == 1)
	{
		read_input(num, FIXED_SIZE);
		show_text(2, (char *[]){v[0], num}, size, dict);
	}
	else if (n == 3)
		two_arg(v[1], v[2]);
	else
		show_text(n, v, size, dict);
	free_dict(dict, size);
	return (0);
}
