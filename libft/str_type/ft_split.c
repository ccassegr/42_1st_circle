/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 04:34:18 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*strdup_split(char const *s, size_t s_len)
{
	size_t		i;
	char		*str;

	i = 0;
	if ((str = (char*)ft_wrmalloc(sizeof(char) * (s_len + 1))) == NULL)
		return (NULL);
	while (i < s_len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_char(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		count_words(char const *s, char c)
{
	int i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		count++;
	return (count);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**sentence;

	if (s == NULL)
		return (NULL);
	if ((sentence = (char**)ft_wrmalloc(sizeof(char*)
		* ((count_words(s, c) + 1)))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			sentence[j] = strdup_split(s + i, count_char(s + i, c));
			j++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		i++;
	}
	sentence[j] = NULL;
	return (sentence);
}
