/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:01:44 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/27 00:20:52 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

// int ft_str(int a, int b){
// 	return (a - b);
// }
// #include<stdio.h>
// int main (void)
// {
// 	int arr[10] = {1,23,3,4,5,6,7,8};

// 	printf("%d",ft_is_sort(arr, 8, ft_str));

// }
