/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:19:36 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/15 05:30:57 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkbase(char *s, int i, int j)
{
	int	l;

	l = -1;
	while (s[++l])
	{
		if (s[l] == '+' || s[l] == '-')
			return (0);
		if ((s[l] >= 9 && s[l] <= 13) || s[l] == 32)
			return (0);
	}
	if (l < 2)
		return (0);
	while (s[i])
	{	
		j = i;
		while (s[++j] != s[i] && s[j])
			continue ;
		if (j != l)
			return (0);
		i++;
	}
	return (l);
}

int	is_base(char nb, char *base)
{
	int	l;

	l = -1;
	while (base[++l])
		if (base[l] == nb)
			return (l);
	return (-1);
}

int	reverse_decimal(char *str, char *base, int l, int negative)
{
	int	i;
	int	mul;
	int	value;

	i = 0;
	value = 0;
	mul = 1;
	while (is_base(str[i], base) != -1)
		i++;
	while (--i > -1)
	{
		if (negative)
			value -= is_base(str[i], base) * mul;
		else
			value += is_base(str[i], base) * mul;
		mul *= l;
	}
	return (value);
}

int	ft_atoi_base(char *str, char *base)
{
	int	l;
	int	negative;

	l = checkbase(base, 0, 0);
	if (!l)
		return (0);
	negative = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			negative = !negative;
	return (reverse_decimal(str, base, l, negative));
}

/*
#include <stdio.h>
int	main(void)
{
	printf("1: %d\n", ft_atoi_base("1010", "01")); //10
	printf("2: %d\n", ft_atoi_base("-1010", "01")); //-10
	printf("3: %d\n", ft_atoi_base("   -1010", "01")); //-10
	printf("4: %d\n", ft_atoi_base("+7", "0123456789")); //7
	printf("5: %d\n", ft_atoi_base("AB", "0123456789ABCDEF")); //171
	printf("6: %d\n", ft_atoi_base("11111111", "01")); //255
	printf("7: %d\n", ft_atoi_base("XYZ", "")); //0 (invalid)
	printf("8: %d\n", ft_atoi_base("XYZ", "X")); //0 (invalid)
	printf("9: %d\n", ft_atoi_base("XYZ", "X+")); //0 (invalid)
	printf("10: %d\n", ft_atoi_base("XYZ", "XYX")); //0 (invalid)
	printf("11: %d\n", ft_atoi_base("XYZ", "XYZ-")); //0 (invalid)
	printf("12: %d\n", ft_atoi_base("XYZ", "  XYZ")); //0 (invalid)
	printf("13: %d\n", ft_atoi_base("", "01")); //0 (empty string)
	return (0);
}
*/