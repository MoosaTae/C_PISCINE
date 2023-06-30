/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:11:35 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/28 13:06:30 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*arr;

	i = -1;
	arr = malloc(sizeof(int) * length);
	if (!arr)
		return (0);
	while (++i < length)
		arr[i] = (*f)(tab[i]);
	return (arr);
}
