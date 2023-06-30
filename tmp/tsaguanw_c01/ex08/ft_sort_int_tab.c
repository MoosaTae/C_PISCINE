/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaguanw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:51:00 by tsaguanw          #+#    #+#             */
/*   Updated: 2023/06/13 23:40:33 by tsaguanw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i <= (size - 1))
	{
		j = i;
		while (j <= (size - 1))
		{
			if (tab[i] > tab[j])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
		j++;
		}
	i++;
	}
}

/*int main()
{
	int arr[] = {4,9, 1, 3, 5,2};
	ft_sort_int_tab(arr, 6);
	
	int i =0;
	while(i<6)
	{
		printf("%d", arr[i]); 
		i++;
	}
}*/
