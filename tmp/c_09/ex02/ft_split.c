/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjairew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:10:45 by wjairew           #+#    #+#             */
/*   Updated: 2023/06/28 17:25:44 by wjairew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (*(sep + i) != '\0')
	{
		if (c == *(sep + i))
			return (1);
		i++;
	}
	return (0);
}

int	count_word_split(char *str, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (*(str + i) != '\0')
	{
		while (*(str + i) && check_is_sep(*(str + i), sep))
			i++;
		while (*(str + i) && !(check_is_sep(*(str + i), sep)))
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	*str_copy_nonsep(char *str, char *sep)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (*(str + i))
	{
		if (check_is_sep(*(str + i), sep))
			break ;
		i++;
	}
	res = malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		*(res + j) = *(str + j);
		j++;
	}
	*(res + j) = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	char	**temp;
	int		len_word_split;
	int		i;

	len_word_split = count_word_split(str, charset);
	res = malloc((len_word_split + 1) * sizeof(char *));
	temp = res;
	i = 0;
	while (*(str))
	{
		while (*(str) && check_is_sep(*(str), charset))
			str++;
		if (*(str))
			*(res + (i++)) = str_copy_nonsep(str, charset);
		while (*(str) && !check_is_sep(*(str), charset))
			str++;
	}
	*(res + i) = 0;
	return (temp);
}
/*
int	main(void)
{
	char **test = ft_split("good, morning","o");
	// test = ["g","d ,m","rning"]
	int i = 0;
	while (test[i] != 0)
	{
		printf("%s\n",test[i]);
		i++;
	}
	return (0);
}
*/
