/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   
printf("\n");
ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:59:10 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/13 19:07:06 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

int	checkbase(char *str)
{
	int	l;
	int	i;
	int	j;

	l = -1;
	while (str[++l])
	{
		if (str[l] == '+' || str[l] == '-')
			return (0);
		if ((str[l] >= 9 && str[l] <= 13) || str[l] == 32)
			return (0);
	}
	if (l < 2)
		return (0);
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[i] != str[j] && str[j])
			j++;
		if (j != l)
			return (0);
		i++;
	}
	return (l);
}

void	print_base(long long int nbr, char *base, int l)
{
	if (nbr < 0)
	{
		put_char('-');
		print_base(-nbr, base, l);
	}
	else if (nbr >= l)
	{
		print_base (nbr / l, base, l);
		print_base (nbr % l, base, l);
	}
	else
	{
		put_char(*(base + nbr));
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;

	l = checkbase(base);
	if (l == 0)
		return ;
	print_base(nbr, base, l);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		nbr = 2023;
// 	char	base[20] = "01";

// 	ft_putnbr_base(nbr, base);

// }