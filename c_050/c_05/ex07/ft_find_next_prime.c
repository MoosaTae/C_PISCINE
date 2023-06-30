/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:00:09 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/15 02:16:25 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int			ans;
	long long	i;

	ans = 2;
	if (nb < 3)
		return (ans);
	if (nb % 2)
		ans = nb;
	else
		ans = nb + 1;
	while (1)
	{
		i = 1;
		while (++i < ans && i * i <= ans)
			if (!(ans % i))
				break ;
		if (i * i > ans)
			return (ans);
		ans += 2;
	}
}
