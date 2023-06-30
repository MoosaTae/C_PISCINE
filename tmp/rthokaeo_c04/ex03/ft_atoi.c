/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthokaeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:15:01 by rthokaeo          #+#    #+#             */
/*   Updated: 2023/06/20 15:47:50 by rthokaeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	result;

	result = 0;
	sign = whitespc(str, &i);
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		result *= 10;
		result += *(str + i) - '0';
		i++;
	}
	result *= sign;
	return (result);
}

/*int	main(void)
{
	char s[20] = "---+--+1234ab567";
	printf("%d\n", ft_atoi(s));
	return (0);
}*/
