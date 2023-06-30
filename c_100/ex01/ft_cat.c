/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 01:03:27 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/27 01:34:47 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <libgen.h>
#define BUF_SIZE 30720  // A little less than 30 ko.

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_read_file(char *file_path)
{
	int		fd;
	int		read_size;
	char 	buffer[BUF_SIZE];

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ft_cat: ");
		ft_putstr(basename(file_path));
		ft_putstr(": ");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
		return ;
	}
	while ((read_size = read(fd, buffer, BUF_SIZE - 1)) > 0)
	{
		buffer[read_size] = '\0';
		ft_putstr(buffer);
	}
	close(fd);
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
	{
		read_input();
	}
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
