/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 08:55:27 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t c;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	c = 0;
	if (size == 0)
		return (j);
	while (src[c] != '\0' && c + i < size - 1)
	{
		dst[c + i] = src[c];
		c++;
	}
	if ((c + i) == size && c != 0)
		dst[(c + i) - 1] = '\0';
	else
		dst[c + i] = '\0';
	if (i < size)
		return (i + j);
	if (i >= size || dst[i + 1] != '\0')
		return (j + size);
	return (i);
}
