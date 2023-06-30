/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:45 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/09 16:49:27 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	loop2(char a, char b)
{
	char	c;
	char	d;

	c = a - 1;
	while (++c <= '9')
	{
		d = '0' - 1;
		if (c <= a)
		{
			d = b;
		}
		while (++d <= '9')
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, " ", 1);
			write(1, &c, 1);
			write(1, &d, 1);
			if (a != '9' || b != '8')
			{
				write(1, ", ", 2);
			}
		}
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = '0' - 1;
	while (++a <= '9')
	{
		b = '0' - 1;
		while (++b <= '9')
		{
			loop2(a, b);
		}
	}
}
