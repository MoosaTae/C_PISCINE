/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wongamph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:53:00 by wongamph          #+#    #+#             */
/*   Updated: 2023/06/14 12:34:06 by wongamph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (((*(str + i) >= 'A') && (*(str + i) <= 'Z')))
		{
			*(str + i) = *(str + i) + 32;
		}
		i++;
	}
	return (str);
}