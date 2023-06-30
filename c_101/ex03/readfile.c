/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:51:45 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/29 23:13:16 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_file_count(char *filepath)
{
	int			file;
	int			size;
	int			size2;
	char		buf[__BUFF];
	extern int	errno;

	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		size2 = 0;
		size = read(file, buf, __BUFF);
		while (size != 0)
		{
			size2 += size;
			size = read(file, buf, __BUFF);
		}
		return (size2);
	}
	else
		return (-1);
}

void	buf_print(int file, char buf[__BUFF])
{
	int	bufsize;

	bufsize = read(file, buf, __BUFF);
	while (bufsize != 0)
	{
		bufsize = read(file, buf, __BUFF);
		ft_putstr_buf(buf, bufsize);
	}
}

void	ft_file_get(char *filepath, int size2, int size)
{
	int		i;
	int		bufsize;
	int		file;
	char	buf[__BUFF];

	file = open(filepath, O_RDONLY);
	i = 0;
	bufsize = read(file, buf, __BUFF);
	while (bufsize != 0
		&& ((i + 1) * __BUFF < size2 - size))
	{
		bufsize = read(file, buf, __BUFF);
		i++;
	}
	if (size >= size2)
		i = -1;
	else
		i = (size2 - size) - (i * __BUFF) - 1;
	while (++i < __BUFF && i < bufsize)
		ft_putchar(buf[i], 1);
	buf_print(file, buf);
}

void	no_args(void)
{
	char	buf;
	int		i;

	i = read(1, &buf, 1);
	while (i != 0)
		i = read(1, &buf, 1);
}
