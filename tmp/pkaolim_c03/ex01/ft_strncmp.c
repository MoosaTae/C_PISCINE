/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaolim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:18:56 by pkaolim           #+#    #+#             */
/*   Updated: 2023/06/13 21:59:46 by pkaolim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (i < n && n != 0)
		{
			if (s1[i] != '\0' && s2[i] != '\0' && (s1[i] != s2[i]))
				i++;
			else
				return (s1[0] - s2[0]);
		}
	}
	return (s1[0] - s2[0]);
}

// int main()
// {
// 	char t1[] = "Pakkawat";
// 	char t2[] = "Pakl";
// 	char t3[] = "";
// 	char t4[5];
// 	unsigned int i = 5;
// 	printf("%d\n",ft_strncmp(t1,t2,i));
// 	printf("%d\n\n",strncmp(t1,t2,i));

// 	printf("%d\n",ft_strncmp(t2,t3,i));
// 	printf("%d\n\n",strncmp(t2,t3,i));

// 	printf("%d\n",ft_strncmp(t3,t4,i));
// 	printf("%d\n\n",strncmp(t3,t4,i));

// 	printf("%d\n",ft_strncmp(t2,t3,0));
// 	printf("%d\n",strncmp(t2,t3,0));
// }