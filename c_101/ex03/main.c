/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sawongpr <sawongpr@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/06/29 22:44:50 by sawongpr		  #+#	#+#			 */
/*   Updated: 2023/06/29 22:50:16 by sawongpr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft.h"

// Function for handling errors
void	handle_error(int argc, char **argv, int i, int oc)
{
	int		size;

	size = ft_file_count(argv[i]);
	if (size == -1)
	{
		ft_putstr(basename(argv[0]), 2);
		ft_putstr(": ", 2);
		ft_putstr(argv[i], 2);
		ft_putstr(": ", 2);
		ft_putstr(strerror(errno), 2);
		ft_putchar('\n', 2);
	}
	else
	{
		if (argc > 4)
		{
			if (i != 3)
				ft_putchar('\n', 1);
			ft_putstr_headfile(argv[i]);
		}
		ft_file_get(argv[i], size, oc);
	}
}

void	print_file(int argc, char **argv, int oc)
{
	int		i;

	i = 2;
	while (++i < argc)
		handle_error(argc, argv, i, oc);
}

int	main(int argc, char **argv)
{
	int			oc;
	extern int	errno;

	if (argc < 4)
		no_args();
	else if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		oc = ft_atoi(argv[2]);
		if (oc != -1)
		{
			print_file(argc, argv, oc);
		}
		else
		{
			ft_putstr(basename(argv[0]), 2);
			ft_putstr(": illegal offset -- ", 2);
			ft_putstr(argv[2], 2);
			ft_putchar('\n', 2);
		}
	}
}
