/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:37:51 by alpeliss          #+#    #+#             */
/*   Updated: 2023/06/29 22:24:07 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	cal_size(char *file)
{
	int		fd;
	char	tmp;
	int		sz;

	fd = open(file, O_RDONLY);
	read(fd, &tmp, 1);
	if (errno)
	{
		close(fd);
		errno = 0;
		return (-1);
	}
	sz = 1;
	while (read(fd, &tmp, 1) && !errno)
		sz++;
	close(fd);
	return (sz);
}

int	print_end_file(char *file, int nb)
{
	int		sz;
	int		fd;
	char	*start;
	char	*end;

	sz = cal_size(file);
	fd = open(file, O_RDONLY);
	start = malloc((sz - nb) * sizeof(char));
	read(fd, start, sz - nb);
	free(start);
	if (nb > sz)
		nb = sz;
	end = malloc(nb * sizeof(char));
	read(fd, end, nb);
	write(1, end, nb);
	free(end);
	close(fd);
	return (0);
}

int	check(int argc, char **argv)
{
	int	i;

	if (argc < 4)
		return (0);
	if (ft_strcmp(argv[1], "-c"))
		return (0);
	i = 0;
	while (argv[2][i] && (argv[2][i] == ' ' ||
		(argv[2][i] > 8 && argv[2][i] < 14)))
		i++;
	if (argv[2][i] == '-' || argv[2][i] == '+')
		i++;
	if (argv[2][i] < '0' || argv[2][i] > '9')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb;

	i = 3;
	if (!check(argc, argv))
		return (0);
	nb = ft_atoi(argv[2]);
	if (nb < 0)
		nb = -nb;
	while (i < argc)
	{
		if (argc > 4)
		{
			write(1, "==> ", 4);
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, "<==\n", 4);
		}
		print_end_file(argv[i], nb);
		if (argc > 4 && i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
