/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:36:55 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/12 16:37:25 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkspace(char str)
{
	if (str == ' ' || str == '\f' || str == '\n')
		return (1);
	if (str == '\r' || str == '\t' || str == '\v')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	ans;
	int	pn;

	pn = 1;
	ans = 0;
	while (checkspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pn *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ans *= 10;
		if (pn == -1)
			ans -= *str - '0';
		if (pn == 1)
			ans += *str - '0';
		str++;
	}
	return (ans);
}
