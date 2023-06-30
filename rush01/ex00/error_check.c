/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nawuttiv <nawuttiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:05:14 by nawuttiv          #+#    #+#             */
/*   Updated: 2023/06/18 21:09:13 by nawuttiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky_scraper.h"

int	ft_count_num(char *str)
{
	int	nlen;

	nlen = 0;
	while (*str != '\0')
	{
		if (*str >= '1' && *str <= '9')
		{
			nlen++;
		}
		str++;
	}
	return (nlen);
}

int	ft_check_numspc(char *str, int size)
{
	int		i;
	char	max;

	max = size + '0';
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '1' || str[i] > max) && (str[i] != ' '))
			return (0);
		if ((str[i] == ' ') && (str[i + 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_size(int nlen)
{
	int	size;
	int	i;

	i = 16;
	size = nlen / 4;
	while (i <= 36)
	{
		if ((size >= 4 && size <= 9) && (nlen == i))
			return (size);
		i += 4;
	}
	return (0);
}

int	check_input(int size, int argc, char *argv)
{
	int	num;
	int	len;

	num = ft_check_numspc(argv, size);
	len = ft_strlen(argv);
	if (num == 1 && argc == 2 && size)
	{
		return (1);
	}
	else
	{
		if (argc != 2)
			ft_putstr("Error\nYou can enter only 2 argument");
		else if (num == 0)
			ft_putstr("Error\nPlease enter the correct format");
		else
			ft_putstr("Error");
		return (0);
	}
}

int	*split_str(int size, char *argv)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	j = 0;
	arr = malloc(sizeof(int) * size * size + 1);
	while (++i <= size * size)
	{
		arr[i] = ft_atoi(&argv[j]);
		j += 2;
	}
	return (arr);
}
