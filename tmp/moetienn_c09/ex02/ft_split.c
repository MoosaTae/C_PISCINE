/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moetienn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:34:32 by moetienn          #+#    #+#             */
/*   Updated: 2023/06/27 16:59:33 by moetienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	charset_is_sep(char sep, char *charset)
{
	while (*charset)
	{
		if (*charset == sep)
			return (1);
		charset++;
	}
	return (0);
}

int	count_sub_strings(char *str, char *charset)
{
	int	count_subs;
	int	in_my_string;

	count_subs = 0;
	in_my_string = 1;
	while (*str)
	{
		if (charset_is_sep(*str, charset))
		{
			in_my_string = 1;
		}
		else if (!charset_is_sep(*str, charset) && in_my_string)
		{
			count_subs++;
			in_my_string = 0;
		}
		str++;
	}
	return (count_subs);
}

char	*ft_strdup(char *src, char *charset)
{
	char	*dest;
	char	*tmp;
	int		i;

	i = 0;
	tmp = src;
	while (*tmp && (!charset_is_sep(*tmp++, charset)))
	{
		i++;
	}
	dest = (char *)malloc(sizeof(char) * (i + 1));
	tmp = dest;
	while (*src && i > 0)
	{
		i--;
		*tmp++ = *src++;
	}
	*tmp = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	char	**tmp;
	int		in_my_string;

	in_my_string = 1;
	strs = (char **)malloc((count_sub_strings(str, charset) + 1)
			* sizeof(char *));
	tmp = strs;
	while (*str)
	{
		if (charset_is_sep(*str, charset))
		{
			in_my_string = 1;
		}
		else if (!charset_is_sep(*str, charset) && in_my_string)
		{
			in_my_string = 0;
			*tmp = ft_strdup(str, charset);
			tmp++;
		}
		str++;
	}
	*tmp = NULL;
	return (strs);
}

/*int	main()
{
	char	**tab;
//	char	*s = "good morning";
//	char	*sep = "o";

	tab = ft_split("good, morning", "o");
	while(*tab)
	{
		printf("%s\n", *tab++);
	}
	return (0);
}*/
