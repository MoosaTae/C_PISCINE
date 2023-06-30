/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:03:18 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/22 21:10:02 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>

// void	put_char(char ch)
// {
// 	write(1, &ch, 1);
// }

// void	ft_putnbr(int nb)
// {
// 	if (nb == -2147483648)
// 		write(1, "-2147483648", 11);
// 	else if (nb < 0)
// 	{
// 		put_char('-');
// 		ft_putnbr(-nb);
// 	}
// 	else if (nb > 9)
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putnbr(nb % 10);
// 	}
// 	else
// 	{
// 		put_char(nb + '0');
// 	}
// }

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = -1;
	while (++i < length)
		(*f)(tab[i]);
}

// int	main(void)
// {
// 	int	arr[] = {1, 2, 3, 4};

// 	ft_foreach(arr, 4, &ft_putnbr);
// 	return (0);
// }
