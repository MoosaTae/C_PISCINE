/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:41:32 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/24 00:35:12 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_display_file(char *path)
{
	int		size;
	int		fd;
	char	buf[BUF_SIZE + 1];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	size = read(fd, buf, BUF_SIZE);
	if (size == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	buf[size] = 0;
	ft_putstr(buf);
}
