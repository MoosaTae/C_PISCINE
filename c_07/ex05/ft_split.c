/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:11:22 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/19 17:46:26 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	count_char(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (*str++ && !is_sep(*str, charset))
		cnt++;
	return (cnt);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			cnt++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (cnt);
}

char	*strncpy_sep(char **str, char *split_str, char *charset)
{
	int	j;

	j = 0;
	while (**str && !is_sep(**str, charset))
		split_str[j++] = *(*str)++;
	split_str[j] = '\0';
	return (split_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**split_str;
	int		i;
	int		j;

	split_str = malloc(sizeof(char *) * count_words(str, charset) + 1);
	if (!split_str)
		return (0);
	i = 0;
	j = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			split_str[i] = malloc(sizeof(char) * count_char(str, charset) + 1);
			if (!split_str[i])
				return (0);
			split_str[i] = strncpy_sep(&str, split_str[i], charset);
			i++;
		}
	}
	split_str[i] = 0;
	return (split_str);
}

// int	main(void)
// {
// 	char str[] = "hello";
// 	char charset[] = "";

// 	char **output = ft_split(str, charset);
// 	printf("%s", output[0]);
// 	// for (int i = 0; output[i]; ++i)
// 	// 	printf("%s\n", output[i]);
// }