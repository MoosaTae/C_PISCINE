/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 01:03:27 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/29 21:59:26 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static int	msg_error(int err, char *file)
{
	if (err)
	{
		write(2, "cat: ", 5);
		write(2, file, ft_strlen(file));
		write(2, ": ", 2);
		write(2, strerror(err), ft_strlen(strerror(err)));
		write(2, "\n", 1);
		return (1);
	}
	return (0);
}

void	ft_read_file(char *file_path)
{
	int		fd;
	int		tmp;
	char	buffer[BUF_SIZE];

	fd = open(file_path, O_RDONLY);
	if (!msg_error(errno, file_path))
	{
		read(fd, buffer, 1);
		if (!msg_error(errno, file_path))
		{
			write(1, buffer, 1);
			tmp = read(fd, buffer, BUF_SIZE);
			while (tmp)
			{
				write(1, buffer, tmp);
				tmp = read(fd, buffer, BUF_SIZE);
			}
		}
		close(fd);
		errno = 0;
	}
}

void	read_input(void)
{
	char	ch;
	char	buf[BUF_SIZE];
	int		i;
	int		fd;

	i = 0;
	fd = read(0, &ch, 1);
	while (fd > 0 && ch != '\n' && i + 1 < BUF_SIZE)
	{
		buf[i++] = ch;
		fd = read(0, &ch, 1);
	}
	buf[i] = '\0';
	ft_read_file(buf);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		read_input();
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_read_file(argv[i]);
			i++;
		}
	}
	return (0);
}
