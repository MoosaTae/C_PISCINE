/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:36:33 by rthokaeo          #+#    #+#             */
/*   Updated: 2023/06/22 15:53:38 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	errortest(char *str)
{
	int	len;
	int	i;
	int	dup;

	len = 0;
	while (*(str + len))
		len++;
	i = 0;
	if (*(str + i) == '\0' || len == 1)
		return (0);
	while (*(str + i))
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == '-' || str[i] == '+')
			return (0);
		dup = i + 1;
		while (dup < len)
		{
			if (*(str + i) == *(str + dup))
				return (0);
			dup++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	error;
	int		len;
	long	n;

	error = errortest(base);
	len = 0;
	n = nbr;
	while (*(base + len))
		len++;
	if (error == 1)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < len)
			ft_putchar(*(base + n));
		if (n >= len)
		{
			ft_putnbr_base(n / len, base);
			ft_putnbr_base(n % len, base);
		}
	}
}

/*int	main(void)
{
	ft_putnbr_base(-2147483648, "0123456789");
	write(1,"\n",1);
	ft_putnbr_base(15, "01");
	write(1,"\n",1);
	ft_putnbr_base(15, "0123456789ABCDEF");
	write(1,"\n",1);
	ft_putnbr_base(15, "poneyvif");
	return (0);
}*/
