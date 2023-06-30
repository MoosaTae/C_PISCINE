/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:29:14 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/27 21:07:11 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_zero(char op, int n2)
{
	if (n2 == 0)
	{
		if (op == '/')
		{
			ft_putstr("Stop : division by zero");
			return (0);
		}
		else if (op == '%')
		{
			ft_putstr("Stop : modulo by zero");
			return (0);
		}
	}
	return (1);
}

void	do_op(int n1, char op, int n2)
{
	int		(*fn[5])(int, int);

	fn[0] = add;
	fn[1] = sub;
	fn[2] = div;
	fn[3] = mul;
	fn[4] = mod;
	if (op == '+')
		ft_putnbr(fn[0](n1, n2));
	else if (op == '-')
		ft_putnbr(fn[1](n1, n2));
	else if (op == '*')
		ft_putnbr(fn[3](n1, n2));
	else if ((op == '/' || op == '%') && check_zero(op, n2))
	{
		if (op == '/')
			ft_putnbr(fn[2](n1, n2));
		else if (op == '%')
			ft_putnbr(fn[4](n1, n2));
	}
	ft_putchar('\n');
}

char	check_op(char *str)
{
	if (ft_strlen(str) == 1 && (*str == '+' || *str == '-'
			|| *str == '/' || *str == '*' || *str == '%'))
		return (*str);
	else
		ft_putstr("0\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	char	op;

	if (argc != 4)
		return (0);
	x = atoi(argv[1]);
	y = atoi(argv[3]);
	op = check_op(argv[2]);
	if (op)
		do_op(x, op, y);
	return (0);
}
