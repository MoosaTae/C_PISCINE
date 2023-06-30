/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthokaeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:12:21 by rthokaeo          #+#    #+#             */
/*   Updated: 2023/06/20 14:18:43 by rthokaeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

/*int	main(void)
{
	char	a[20] = "HelloWorld";
	printf("%lu\n", strlen(a));
	printf("%d\n", ft_strlen(a));
	return (0);
}*/
