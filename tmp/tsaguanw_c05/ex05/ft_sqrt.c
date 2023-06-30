/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:02:02 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/27 16:10:13 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 2;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i)
	{
		if ((i * i) == nb)
			return (i);
		else if ((i * i) > nb)
			return (0);
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int main()
{
	printf("%d", ft_sqrt(214743647));
}*/
