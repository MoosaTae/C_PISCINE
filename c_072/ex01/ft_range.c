/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 07:11:38 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/20 20:10:43 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*a;

	size = max - min;
	if (size <= 0)
		return (0);
	a = (int *)malloc(size * sizeof(int));
	if (a == 0)
		return (0);
	i = -1;
	while (++i < size)
	{
		a[i] = min + i;
	}
	return (a);
}
