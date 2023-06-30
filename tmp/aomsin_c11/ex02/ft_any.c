/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakitwo <thakitwo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:29:24 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/26 23:46:35 by thakitwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

// int	ft_str(char *str)
// {
// 	if (*str == '0')
// 		return (1);
// 	return (0);
// }

// int main(int argggggggg, char **a)
// {
// 	printf("%d", ft_any(a, &ft_str));

// }
