/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:03:48 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/20 17:41:00 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str);

int	checkbase(char *str);

char	*shift_left(char *new_base)
{
	int	base;

	base = -1;
	while (new_base[++base + 1])
		new_base[base] = new_base[base + 1];
	new_base[base] = '\0';
	return (new_base);
}

char	*itoa_base(long long nbr, char *bstr, int len_str, int positive)
{
	char	*new_base;
	int		base;

	base = ft_strlen(bstr);
	new_base = malloc(sizeof(char) * len_str + 2);
	if (!new_base)
		return (0);
	new_base[len_str + 1] = '\0';
	if (nbr == 0)
	{
		new_base[0] = bstr[0];
		return (new_base);
	}
	while (len_str)
	{
		new_base[len_str--] = bstr[nbr % base];
		nbr /= base;
	}
	if (!positive)
		new_base[0] = '-';
	else
		new_base = shift_left(new_base);
	return (new_base);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	nb;
	int			positive;
	int			mul;
	int			len_str;

	if (!checkbase(base_to) || !checkbase(base_from))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	mul = 1;
	len_str = 0;
	positive = 1;
	if (nb < 0)
	{
		positive = 0;
		nb *= -1;
	}
	while (mul < nb + 1)
	{
		mul *= ft_strlen(base_to);
		len_str++;
	}
	return (itoa_base(nb, base_to, len_str, positive));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char nbr[] = "a";
// 	char base_from[] = "a";
// 	char base_to[] = "1";

// 	printf("%s", ft_convert_base(nbr, base_from, base_to));
// }