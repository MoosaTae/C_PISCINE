/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:31:53 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/15 09:57:28 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkbase(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = i + 1;
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (1);
		if (str[i] == '+' || str[i] == '-')
			return (1);
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	if (checkbase(base))
		return (0);
	nstr = ft_strlen(str);
	nbase = ft_strlen(base);
	if (nbase < 2)
		return (0);
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
