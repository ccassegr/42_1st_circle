/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:31:33 by ccassegr          #+#    #+#             */
/*   Updated: 2020/08/31 17:22:46 by claire           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char			*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		if (s[i] == ((char)c))
			return (((char *)s) + i);
		else
			i++;
	}
	if (s[i] == '\0' && s[i] == ((char)c))
		return (((char *)s) + i);
	else
		return (NULL);
}

static char		*ft_fill_join(char const *s, char *result, size_t i)
{
	int j;

	j = 0;
	while (s[j])
		result[i++] = s[j++];
	result[i++] = '\0';
	return (result);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(result = malloc((len_s1 + len_s2 + 1) * sizeof(char))))
		return (NULL);
	if (!s1 && s2)
		result = ft_fill_join(s2, result, 0);
	else if (s1 && !s2)
		result = ft_fill_join(s1, result, 0);
	else if (!s1 && !s2)
		return (0);
	else
	{
		result = ft_fill_join(s1, result, 0);
		result = ft_fill_join(s2, result, len_s1);
		free((char *)s1);
	}
	return (result);
}

char			*ft_strduplen(const char *src, size_t len)
{
	char		*copy;
	size_t		j;
	size_t		tmp;

	tmp = 0;
	j = 0;
	if (!(copy = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (j < len && src[j] != '\0')
	{
		if (src[j] == '\n' && j == 0)
			j++;
		copy[tmp] = src[j];
		j++;
		tmp++;
	}
	copy[tmp] = '\0';
	return (copy);
}
