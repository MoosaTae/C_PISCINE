/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:12:18 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/29 23:07:40 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

void	ft_putstr(char *str, int out)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++], out);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(char *s)
{
	int	i;
	int	m;
	int	total;

	i = 0;
	total = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == ' ')
		i++;
	m = 1;
	if (s[i] == '-')
	{
		m = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		total = total * 10 + (s[i] - '0') * m;
		i++;
	}
	return (total);
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}
