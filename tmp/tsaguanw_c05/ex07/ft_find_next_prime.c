/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:54:22 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/24 14:34:31 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i <= (nb / 2))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	next_nb;

	i = 2;
	next_nb = nb;
	if (nb <= 1)
		return (2);
	if (check_is_prime(nb) == 1)
		return (nb);
	else
	{
		while (check_is_prime(next_nb) != 1)
		{
			next_nb ++;
		}
		return (next_nb);
	}
}

/*#include <stdio.h>
int main(void)
{
        printf("%d -> %d\n",0,ft_find_next_prime(0));
        printf("%d -> %d\n",2,ft_find_next_prime(2));
        printf("%d -> %d\n",5,ft_find_next_prime(5));
        printf("%d -> %d\n",8,ft_find_next_prime(8));
        printf("%d -> %d\n",12,ft_find_next_prime(12));
        printf("%d -> %d\n",14,ft_find_next_prime(14));
        printf("%d -> %d\n",2147483646,ft_find_next_prime(2147483646));
}*/
