/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:25:55 by rthokaeo          #+#    #+#             */
/*   Updated: 2023/06/22 15:57:20 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	errortest(char *str)
{
	int	len;
	int	i;
	int	dup;

	len = 0;
	i = 0;
	while (*(str + len))
		len++;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (*(str + i))
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == '+' || str[i] == '-')
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
	return (i);
}

int	whitespc(char *str, int *ptr_i)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	while (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			sign *= -1;
		i++;
	}
	*ptr_i = i;
	return (sign);
}

int	nb_base(char str, char *base)
{
	int	nb;

	nb = 0;
	while (*(base + nb))
	{
		if (str == *(base + nb))
			return (nb);
		nb++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb1;
	int	nb2;
	int	sign;
	int	len_test;

	nb1 = 0;
	i = 0;
	len_test = errortest(base);
	if (len_test >= 2)
	{
		sign = whitespc(str, &i);
		nb2 = nb_base(*(str + i), base);
		while (nb2 != -1)
		{
			nb1 = (nb1 * len_test) + nb2;
			i++;
			nb2 = nb_base(*(str + i), base);
		}
		return (nb1 *= sign);
	}
	return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_atoi_base("	+++++--133742", "0123456789"));
	printf("%d\n", ft_atoi_base("	     ---101010", "01"));
	printf("%d\n", ft_atoi_base(" 	+---539", "0123456789abcdef"));
	return (0);
}*/
