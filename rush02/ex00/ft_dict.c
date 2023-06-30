/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnitipan <nnitipan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:30:09 by nnitipan          #+#    #+#             */
/*   Updated: 2023/06/26 21:29:33 by nnitipan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	check_space(long long int num, long long int dict_num, int next_num)
{
	if (dict_num >= 100 && num % dict_num != 0 && next_num <= 100)
		ft_putstr(" and ");
	else if (!(num == dict_num) && num % dict_num != 0 && next_num < 10)
		ft_putstr("-");
	else if (next_num < num && next_num != 0)
		ft_putstr(", ");
}

void	print_key(long long int num, t_Dict *dict)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (num == dict[i].key && num != 0)
			ft_putstr(dict[i].value);
		i++;
	}
}

void	find_key(t_Dict *dict, long long int num, int size)
{
	unsigned int	i;

	i = 0;
	if (num <= 20)
		print_key(num, dict);
	else
	{
		i = 31;
		while (i > 0)
		{
			if ((num / dict[i].key) > 0)
			{
				if (dict[i].key >= 100)
				{
					find_key(dict, num / dict[i].key, size);
					ft_putstr(" ");
				}
				ft_putstr(dict[i].value);
				check_space(num, dict[i].key, num % dict[i].key);
				find_key(dict, num % dict[i].key, size);
				break ;
			}
			i--;
		}
	}
}

void	find_value(int key, t_Dict *dict)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (key == dict[i].key)
		{
			ft_putstr(dict[i].value);
			ft_putstr("\n");
		}
		i++;
	}
}
