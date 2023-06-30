/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:58:15 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/28 22:17:18 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str, int d, int len)
{
	int	i;

	i = 0;
	if (len == 0)
	{
		while (str[i])
			i++;
		len = i;
	}
	write(d, str, len);
}

void	ft_display_file(char *path)
{
	int		size;
	int		fd;
	char	buf[2048];

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", 2, 0);
		return ;
	}
	size = read(fd, buf, 2047);
	while (size > 0)
	{
		buf[size] = '\0';
		ft_putstr(buf, 1, size);
		size = read(fd, buf, 2047);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n", 2, 0);
	else if (argc > 2)
		ft_putstr("Too many arguments.\n", 2, 0);
	else
		ft_display_file(argv[1]);
	return (0);
}
