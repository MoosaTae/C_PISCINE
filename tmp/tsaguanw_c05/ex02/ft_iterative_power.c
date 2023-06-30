/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:26:06 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/24 14:57:43 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	var;

	var = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while (power > 0)
	{
		var = var * nb;
		power--;
	}
	return (var);
}
/*#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_power(3,0));
}*/
