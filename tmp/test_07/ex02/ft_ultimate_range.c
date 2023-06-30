/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 07:17:38 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/15 10:28:23 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(size * sizeof(int));
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		++i;
	}
	return (size);
}
