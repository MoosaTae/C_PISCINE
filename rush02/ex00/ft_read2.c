/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_read2.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sawongpr <sawongpr@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/06/26 15:18:22 by sawongpr		  #+#	#+#			 */
/*   Updated: 2023/06/26 23:00:14 by sawongpr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft.h"

int	count_file_char(char *path)
{
	t_Context	ctx;
	char		buffer[FIXED_SIZE];

	ctx.fd = open(path, O_RDONLY);
	ctx.p = 0;
	ctx.n = read(ctx.fd, buffer, FIXED_SIZE);
	while (ctx.n > 0)
	{
		ctx.p += ctx.n;
		ctx.n = read(ctx.fd, buffer, FIXED_SIZE);
	}
	return (ctx.p);
}

int	check_key(long long int key, t_Dict *arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		if (arr[i++].key == key)
			return (0);
	if (key <= 20 || (key <= 100 && key % 10 == 0))
		return (1);
	if (key == 1000 || key == 1000000
		|| key == 1000000000)
		return (1);
	return (0);
}

void	read_input(char *num, int len)
{
	char	buf;
	int		i;
	int		f;

	i = 0;
	f = read(STDIN_FILENO, &buf, 1);
	while (f > 0 && buf != '\n' && i < len - 1)
	{
		num[i++] = buf;
		f = read(STDIN_FILENO, &buf, 1);
	}
	num[i] = '\0';
}
