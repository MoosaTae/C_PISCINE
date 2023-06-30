/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:16:06 by nnitipan          #+#    #+#             */
/*   Updated: 2023/06/26 22:38:29 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	parse_entry(char *line, t_Dict *arr, t_Dict *kv, int *count)
{
	char	*dem;
	int		len;

	dem = ft_strchr(line, ':');
	if (!dem)
		return ;
	dem++;
	kv->key = ft_atoi(line);
	if (check_key(kv->key, arr, *count) == 0)
		return ;
	while (*dem == ' ' || (*dem >= 9 && *dem <= 13))
		dem++;
	len = ft_strlen(dem);
	kv->value = malloc(len + 1);
	if (!kv->value)
		return ;
	*count += 1;
	ft_strncpy(kv->value, dem, len + 1);
}

char	*parse_line(char *start, t_Dict *arr, t_Dict *kv, int *count)
{
	char	*line;

	line = ft_strchr(start, '\n');
	if (!line)
		return (0);
	*line = '\0';
	parse_entry(start, arr, kv, count);
	return (line + 1);
}

t_Dict	*readfile(char *path, int *size)
{
	t_Context	ctx;
	t_Dict		*arr;
	char		*buffer;
	char		*start;

	ctx.count = 0;
	ctx.fd = open(path, O_RDONLY);
	if (ctx.fd == -1)
		return (0);
	arr = malloc(sizeof(t_Dict) * 32);
	ctx.p = count_file_char(path);
	buffer = malloc(sizeof(char) * (ctx.p + 1));
	ctx.n = read(ctx.fd, buffer, ctx.p);
	buffer[ctx.n] = '\0';
	start = parse_line(buffer, arr, &arr[ctx.count], &ctx.count);
	while (start != 0)
		start = parse_line(start, arr, &arr[ctx.count], &ctx.count);
	close(ctx.fd);
	free(buffer);
	*size = ctx.count;
	return (arr);
}
