/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 23:51:51 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		if (s1[i] != set[j])
			j++;
	}
	return (i);
}

static size_t	trim_end(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = ft_strlen(s1) - 1;
	j = 0;
	l = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			l++;
			i--;
		}
		if (s1[i] != set[j])
			j++;
	}
	return (l);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;
	char	*str;
	size_t	len_s1;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	k = trim_start(s1, set);
	len_s1 = ft_strlen(s1);
	if (k == len_s1)
		size = 0;
	else
		size = (ft_strlen(s1) - k - trim_end(s1, set));
	if ((str = ft_wrmalloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (size--)
		str[i++] = s1[k++];
	str[i] = '\0';
	return (str);
}
