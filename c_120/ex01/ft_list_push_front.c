/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:20:11 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/28 21:41:28 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->data = data;
		tmp->next = 0;
	}
	return (tmp);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*push;

	if (*begin_list)
	{
		push = ft_create_elem(data);
		push->next = *begin_list;
		*begin_list = push;
	}
	else
		*begin_list = ft_create_elem(data);

}

// #include <stdio.h>
// #include "ft_list.h"

// int		main(void)
// {
// 	t_list	elem1, elem2, elem3, *begin;

// 	begin = &elem1;
// 	elem1.next = &elem2;
// 	elem2.next = &elem3;
// 	elem3.next = 0;

// 	elem1.data = "toto";
// 	elem2.data = "tata";
// 	elem3.data = "tutu";

// 	ft_list_push_front(&begin, "tasoeur");
// 	while (begin)
// 	{
// 		printf("%s\n", begin->data);
// 		begin = begin->next;
// 	}
// }