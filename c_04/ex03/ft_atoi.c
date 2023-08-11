/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:29:52 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/12 20:52:33 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	negative;
	int	value;

	negative = 0;
	value = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			negative = !negative;
	}
	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		if (negative)
			value -= *str - '0';
		else
			value += *str - '0';
		str++;
	}
	return (value);
}

/*
int	main(void)
{
	printf("%d", ft_atoi("--103"));
	return (0);
}
*/