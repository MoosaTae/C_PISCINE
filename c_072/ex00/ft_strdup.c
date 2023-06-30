/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 07:04:18 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/15 10:28:31 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		l;
	char	*tmp;
	int		i;

	l = 0;
	while (src[l])
		l++;
	tmp = (char *)malloc((l + 1) * sizeof(char));
	if (tmp == 0)
		return (0);
	if (tmp != 0)
	{
		i = 0;
		while (src[i] && i < l)
		{
			tmp[i] = src[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
