/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:17:23 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/22 21:45:18 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	var;

	var = 1;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (nb > 0)
	{
		var = var * nb;
		nb--;
	}
	return (var);
}

/*#include <stdio.h>
int main()
{
	printf("%d", ft_iterative_factorial(4));
}*/
