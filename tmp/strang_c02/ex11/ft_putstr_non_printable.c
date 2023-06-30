/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkitwor <thkitwor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:08:48 by thkitwor          #+#    #+#             */
/*   Updated: 2023/06/13 11:20:32 by thkitwor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	hex(int c)
{
	int	b;

	b = c % 16;
	c = c / 16;
	if (c >= 10)
	{
		print(c - 10 + 'a');
	}
	else
	{
		print(c + '0');
	}
	if (b >= 10)
	{
		print(b - 10 + 'a');
	}
	else
	{
		print(b + '0');
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
		{
			write(1, str, 1);
		}
		else
		{
			if (*str < 0)
			{
				*str += 256;
			}
			write(1, "\\", 1);
			hex(*str);
		}
		str++;
	}
}

// int	main(void)
// {
// 	ft_putstr_non_printable("Coucou\ntu vas bien ?");
// }
