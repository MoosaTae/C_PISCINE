/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:33:06 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/13 20:38:27 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	value;
	int	i;

	value = nb;
	i = 1;
	if (power == 0)
	{
		return (1);
	}
	else if (power < 0)
		return (0);
	while (i < power)
	{
		value *= nb;
		i++;
	}
	return (value);
}
