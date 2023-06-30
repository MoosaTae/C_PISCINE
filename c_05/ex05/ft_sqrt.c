/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:43:50 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/15 00:27:25 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int			l;
	long long	mid;
	int			h;

	if (nb < 1)
		return (0);
	l = 0;
	h = nb;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid < nb)
			l = mid + 1;
		else
			h = mid - 1;
	}
	return (0);
}
