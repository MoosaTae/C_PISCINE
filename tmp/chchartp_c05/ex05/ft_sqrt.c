/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:12:12 by chchartp          #+#    #+#             */
/*   Updated: 2023/06/22 13:36:21 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	j;

	i = nb;
	j = 1;
	if (nb <= 0)
		return (0);
	else
	{
		while (i > j)
		{
			i = (i + j) / 2;
			j = nb / i;
		}
		if ((i * i) == nb)
			return (i);
		else
			return (0);
	}
}

/*#include <stdio.h>

int	main(void)
{
	int	nb;
	int	result;

	nb = 25;
	result = ft_sqrt(nb);
	printf("%d\n", result);
}*/
