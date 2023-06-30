/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:00:42 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/20 17:38:44 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkbase(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ft_strlen(str) < 2)
		return (0);
	while (str[i])
	{
		j = i + 1;
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		if (str[i] == '+' || str[i] == '-')
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check(char str, char *base)
{
	int	i;

	i = 0;
	while (*base)
	{
		if (str == *base)
			return (i);
		base++;
		i++;
	}
	return (-1);
}

int	change(char *str, char *base, int pn)
{
	int	i;
	int	co;
	int	ans;

	ans = 0;
	co = 0;
	while (check(str[co], base) != -1 && str[co])
		co++;
	i = 1;
	while (--co >= 0)
	{
		if (pn < 0)
			ans -= check(str[co], base) * i;
		if (pn > 0)
			ans += check(str[co], base) * i;
		i *= ft_strlen(base);
	}
	return (ans);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nstr;
	int	nbase;
	int	pn;

	pn = 1;
	nstr = ft_strlen(str);
	nbase = ft_strlen(base);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pn *= -1;
		str++;
	}
	return (change(str, base, pn));
}
