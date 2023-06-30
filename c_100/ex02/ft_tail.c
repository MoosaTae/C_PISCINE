/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_tail.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sawongpr <sawongpr@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/06/27 01:03:05 by sawongpr		  #+#	#+#			 */
/*   Updated: 2023/06/27 01:03:46 by sawongpr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define BUFFER_SIZE 4096

void error_message(char *prog_name, char *file_name)
{
	write(2, basename(prog_name), strlen(basename(prog_name)));
	write(2, ": ", 2);
	write(2, file_name, strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", 1);
}

void ft_tail(char *file_name, int n_bytes) {
	char	buffer[BUFFER_SIZE];
	char	*content;
	int		fd = open(file_name, O_RDONLY);
	int		read_size;
	int		total_size = 0;

	if (fd == -1)
	{
		error_message("ft_tail", file_name);
		return ;
	}
	content = malloc(1);
	content[0] = '\0';
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		content = realloc(content, total_size + read_size + 1);
		strncpy(content + total_size, buffer, read_size);
		total_size += read_size;
	}
	if (total_size < n_bytes)
		n_bytes = total_size;
	write(1, content + total_size - n_bytes, n_bytes);
	free(content);
	close(fd);
}

int main(int argc, char **argv)
{
	if (argc != 4 || strcmp(argv[1], "-c") != 0)
	{
		write(2, "Usage: ft_tail -c [N bytes] [file name]\n", 41);
		return (1);
	}
	int	n_bytes = atoi(argv[2]);

	ft_tail(argv[3], n_bytes);
	return (0);
}
