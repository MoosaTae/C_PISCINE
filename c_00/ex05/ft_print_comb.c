/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:45 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/09 15:56:26 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0' - 1;
	while (a++ < '9')
	{
		b = a;
		while (b++ < '9')
		{
			c = b;
			while (c++ < '9')
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (a < '7')
				{
					write(1, ", ", 2);
				}
			}
		}
	}
}