/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:25:25 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/12 16:26:56 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *nb)
{
	int		value;
	int		negative;

	value = 0;
	negative = 0;
	if (*nb == '-')
	{
		nb++;
		negative = 1;
	}
	while (*nb)
	{
		value *= 10;
		if (negative)
			value -= *nb - '0';
		else
			value += *nb - '0';
		nb++;
	}
	return (value);
}
