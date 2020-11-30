/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:19:52 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	str_len = ft_strlen(s) - start;
	if (len < str_len)
		str_len = len;
	i = 0;
	if ((str = ft_wrmalloc(sizeof(char) * (str_len + 1))) == NULL)
		return (NULL);
	if ((size_t)start <= ft_strlen(s))
		while (str_len-- && s[start])
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
