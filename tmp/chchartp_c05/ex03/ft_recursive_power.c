/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchartp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:39:46 by chchartp          #+#    #+#             */
/*   Updated: 2023/06/20 12:43:06 by chchartp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

/*#include <stdio.h>

int	main(void)
{
	int	nb;
	int	power;
	int	result;

	nb = 2;
	power = 5;
	result = ft_recursive_power(nb, power);
	printf("%d\n", result);
}*/
