/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:30:18 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/14 11:31:17 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	write_hexa(unsigned char ch)
{
	put_char("0123456789abcdef"[ch / 16]);
	put_char("0123456789abcdef"[ch % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned char	u_char;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			put_char('\\');
			u_char = str[i];
			write_hexa(u_char);
		}
		else
		{
			put_char(str[i]);
		}
		i++;
	}
}
