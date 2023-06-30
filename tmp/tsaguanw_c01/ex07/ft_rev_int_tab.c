/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:16:55 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/13 22:15:35 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{	
	int	i;
	int	temp;
	int	n;
	int	last;

	i = 0;
	n = size / 2;
	last = size - 1;
	while (i < n)
	{
		temp = tab[i];
		tab[i] = tab[last];
		tab[last] = temp;
		i++;
		last--;
	}
}
/*int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};

	ft_rev_int_tab(arr, 7);
	
	int i =0;
	while(i < 7)
	{	
		printf("%d", arr[i]);
		i++;
	}
	

}*/
