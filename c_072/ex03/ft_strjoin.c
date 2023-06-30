/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:15:12 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/19 16:33:29 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*join_str(char *result, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	if (result == 0)
		return (0);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			result[k++] = strs[i][j];
		if (i + 1 < size)
		{
			j = -1;
			while (sep[++j])
				result[k++] = sep[j];
		}
	}
	result[k] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		k;
	char	*result;

	if (size == 0)
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	i = 0;
	k = 0;
	while (i < size)
		k += str_len(strs[i++]);
	k += str_len(sep) * (size - 1);
	result = malloc(k * sizeof(char) + 1);
	if (result == 0)
		return (0);
	return (join_str(result, strs, sep, size));
}
