/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:43:50 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/21 20:13:44 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	return (nb * ft_recursive_power (nb, power - 1));
}
/*#include <stdio.h>
int main()
{
	printf("%d", ft_recursive_power(0, 0));
}*/
