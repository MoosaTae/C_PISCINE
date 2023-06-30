/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:16:25 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/28 00:37:03 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(long long int nbr);

int	ft_atoi(char *str)
{
	int	np;
	int	ans;

	np = 1;
	ans = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			np *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		ans *= 10;
		if (np == -1)
			ans -= *str - '0';
		else
			ans += *str - '0';
		str++;
	}
	return (ans);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	checkope(char *a, int (*f)(char *))
{
	if (f(a) != 1)
		return (0);
	if (*a != '+' && *a != '*' && *a != '/' && *a != '-' && *a != '%')
		return (0);
	return (1);
}

void	cal(int a, char c, int b, void (*f)(long long int))
{
	if (c == '+')
		f(a + b);
	else if (c == '-')
		f(a - b);
	else if (c == '*')
		f(a * b);
	else if (c == '/')
	{
		if (b == 0)
		{
			write(1, "Stop : division by zero\n", 24);
			return ;
		}
		f(a / b);
	}
	else if (c == '%')
	{
		if (b == 0)
		{
			write(1, "Stop : modulo by zero\n", 23);
			return ;
		}
		f(a % b);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (checkope(argv[2], ft_strlen))
		cal(ft_atoi(argv[1]), argv[2][0], ft_atoi(argv[3]), ft_putnbr);
	else
		write(1, "0", 1);
	return (0);
}
