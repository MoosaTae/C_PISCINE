/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchartp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:27:05 by chchartp          #+#    #+#             */
/*   Updated: 2023/06/20 13:30:21 by chchartp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		i = 0;
		result = 1;
		while (i < power)
		{
			result *= nb;
			i++;
		}
		return (result);
	}
}

/*#include <stdio.h>

int	main(void)
{
	int	nb;
	int	power;
	int	result;

	nb = 2;
	power = 5;
	result = ft_iterative_power(nb, power);
	printf("%d\n", result);
}*/
