/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:46:25 by nnitipan          #+#    #+#             */
/*   Updated: 2023/06/26 20:48:07 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(long long int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putstr("-2");
			nb = 147483648;
		}
		else
		{
			ft_putchar('-');
			nb = -nb;
		}
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = -1;
	while (src[++i] != '\0' && i < n)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
}

char	*ft_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}
