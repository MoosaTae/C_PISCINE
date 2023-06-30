/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:14:55 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/24 14:56:28 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	var;

	var = 1;
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	else
		var = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	return (var);
}
/*#include <stdio.h> 
int main()
{
	printf("%d", ft_fibonacci(2));
}*/
