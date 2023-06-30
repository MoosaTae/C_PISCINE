/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:09:17 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/14 22:49:06 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	div_ab;
	int	mod_ab;

	div_ab = a / b;
	mod_ab = a % b;
	*div = div_ab;
	*mod = mod_ab;
}
/*int main()
{
	int i;
	int j;

	ft_div_mod(42, 2,&i, &j);
	printf("div = %d   mod = %d", i, j); 	
}*/
