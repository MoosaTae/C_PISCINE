/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:03:19 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/14 11:29:56 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(unsigned char c)
{
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}

void	ft_print_addr(unsigned long long addr)
{
	int	i;

	i = 60;
	while (i >= 0)
	{
		ft_putchar("0123456789abcdef"[(addr >> i) & 15]);
		i -= 4;
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	ft_print_line(void *addr, size_t size, unsigned int i)
{
	unsigned char	*p;

	p = (unsigned char *)addr;
	while (++i < 16)
	{
		if (i < size)
			ft_print_hex(p[i]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2)
			ft_putchar(' ');
	}
	i = -1;
	while (++i < 16 && i < size)
	{
		if (p[i] >= 32 && p[i] <= 126)
			ft_putchar(p[i]);
		else
			ft_putchar('.');
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_print_addr((unsigned long long)(addr + i));
		if (size < 16 + i)
			ft_print_line(addr + i, size - i, -1);
		else
			ft_print_line(addr + i, 16, -1);
	i += 16;
	}
	return (addr);
}

// int main() {
// 	char text[] = "Bonjour les aminches...c'est fou tout 
// ce qu'on peut faire avec.\n\0\0print_memory..\nlol.lol.\n ";
// 	ft_print_memory(text, sizeof(text));
// 	return (0);
// }