/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:08:21 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/14 22:44:32 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	var;

	var = *a / *b;
	*b = *a % *b;
	*a = var;
}
/*int main()
{
	int i = 12;
	int j = 2;


	ft_ultimate_div_mod(&i,&j);
	printf("div = %d   mod = %d", i, j);
}*/
