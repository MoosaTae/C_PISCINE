/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:25:31 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/12 16:28:30 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
int		ft_atoi(char *nb);

int	main(int argv, char **argc)
{
	int	x;
	int	y;

	if (argv != 3)
		return (0);
	x = ft_atoi(argc[1]);
	y = ft_atoi(argc[2]);
	if (x < 1 || y < 1)
	{
		return (0);
	}
	rush(x, y);
	return (0);
}
