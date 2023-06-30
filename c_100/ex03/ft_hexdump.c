/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_hexdump.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sawongpr <sawongpr@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/06/27 01:32:43 by sawongpr		  #+#	#+#			 */
/*   Updated: 2023/06/27 01:32:47 by sawongpr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define BUFFER_SIZE 4096

void	error_message(char *prog_name, char *file_name) {
	write(2, basename(prog_name), strlen(basename(prog_name)));
	write(2, ": ", 2);
	write(2, file_name, strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	print_hex(unsigned char c) {
	char *hex = "0123456789abcdef";

	write(1, &hex[c >> 4], 1);
	write(1, &hex[c & 0x0F], 1);
}

void	print_ascii(unsigned char c) {
	if (c >= ' ' && c <= '~')
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	ft_hexdump(char *file_name)
{
	unsigned char	buffer[BUFFER_SIZE];
	int				fd = open(file_name, O_RDONLY);
	int				read_size;
	int				i;

	if (fd == -1)
	{
		error_message("ft_hexdump", file_name);
		return;
	}
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0) {
		for (i = 0; i < read_size; ++i) {
			if (i != 0 && i % 8 == 0)
				write(1, " ", 1);
			print_hex(buffer[i]);
			write(1, " ", 1);
		}
		for (; i < BUFFER_SIZE; ++i) {
			if (i != 0 && i % 8 == 0)
				write(1, " ", 1);
			write(1, "   ", 3);
		}
		write(1, " |", 2);
		for (i = 0; i < read_size; ++i)
			print_ascii(buffer[i]);
		for (; i < BUFFER_SIZE; ++i)
			write(1, " ", 1);
		write(1, "|\n", 2);
	}
	close(fd);
}

int	main(int argc, char **argv) {
	if (argc != 3 || strcmp(argv[1], "-C") != 0)
	{
		write(2, "Usage: ft_hexdump -C [file name]\n", 34);
		return (1);
	}
	ft_hexdump(argv[2]);
	return (0);
}
