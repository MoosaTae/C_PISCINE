/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:31:57 by nnitipan          #+#    #+#             */
/*   Updated: 2023/06/26 23:01:22 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define FIXED_SIZE 2048
# include<fcntl.h>
# include<unistd.h>
# include<stdlib.h>

int				is_valid(char *str);
long long int	ft_atoi(char *str);
int				is_overflow(long long int num);
typedef struct dict{
	long long int	key;
	char			*value;
}t_Dict;

typedef struct context{
	int			fd;
	int			count;
	int			p;
	int			n;
}t_Context;
void			find_key(t_Dict *dict, long long int num, int size);
void			ft_putstr(char *str);
void			ft_putnbr(long long int nb);
void			ft_putchar(char a);
void			ft_strncpy(char *dest, const char *src, int n);
char			*ft_strchr(char *str, char c);
int				ft_strlen(char *str);
void			parse_entry(char *line, t_Dict *arr, t_Dict *kv, int *count);
char			*parse_line(char *start, t_Dict *arr, t_Dict *kv, int *count);
t_Dict			*readfile(char *path, int *size);
int				count_file_char(char *path);
int				check_key(long long int key, t_Dict *arr, int count);
void			free_dict(t_Dict *dict, int size);
void			find_value(int key, t_Dict *dict);
int				is_empty(char *str);
void			read_input(char *num, int len);

#endif