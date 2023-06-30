/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:44:11 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/15 00:14:54 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, const char *argv[])
{
	if (argc != 0)
	{
		while (*argv[0])
			write(1, argv[0]++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
