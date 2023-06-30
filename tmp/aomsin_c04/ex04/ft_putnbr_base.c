/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:45 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/15 02:27:14 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include<stdio.h>

int	checkbase(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1])
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-')
			return (1);
		while (str[j])
		{
			if (str[j] == '+' || str[j] == '-')
				return (1);
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (checkbase(str))
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	basefind(int n, char *base, long long int nbr)
{
	char	str;

	if (nbr >= n)
	{
		basefind(n, base, nbr / n);
		basefind(n, base, nbr % n);
	}
	else
	{	
		str = *(base + nbr);
		write(1, &str, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				n;
	long long int	i;

	i = nbr;
	n = ft_strlen(base);
	if (n == 0 || n == 1)
		return ;
	if (i < 0)
	{
		i *= -1;
		write(1, "-", 1);
	}
	basefind(n, base, i);
}
/*
int	main(void)
{

    
    ft_putnbr_base(10, "0123456789+"); // No output, base contains +
    write(1, "\n", 1);
    ft_putnbr_base(10, "0123456789-"); // No output, base contains -
    write(1, "\n", 1);
    ft_putnbr_base(1000000, "0123456789"); // Expected output: 1000000
    write(1, "\n", 1);
    ft_putnbr_base(1000000, "01"); // Expected output: 11110100001001000000
    write(1, "\n", 1);
    ft_putnbr_base(1000000, "0123456789ABCDEF"); // Expected output: F4240
    write(1, "\n", 1);
    ft_putnbr_base(1000000, "poneyvif"); // Expected output: ineyvif

}*/
