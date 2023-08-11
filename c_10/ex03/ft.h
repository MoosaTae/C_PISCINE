/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:04:18 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/29 23:07:31 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# define __BUFF 32000

void	no_args(void);
void	ft_putchar(char c, int out);
void	ft_putstr(char *str, int out);
int		ft_strlen(char *s);
int		ft_atoi(char *s);
int		ft_strcmp(char *a, char *b);
int		ft_file_count(char *filepath);
void	ft_putstr_buf(char *str, int size);
void	ft_putstr_headfile(char *filepath);
void	ft_file_get(char *filepath, int size2, int size);

#endif