/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:04:34 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		index;
	const char	*mark;
	size_t		len_n;

	len_n = ft_strlen(n);
	index = 0;
	mark = "";
	if (*n == '\0')
		return ((char *)h);
	while (h[index] && index < len)
	{
		if (h[index] == n[0] && index < len)
		{
			mark = h + index;
			if (ft_strncmp(h + index, n, len_n) == 0 &&
					(index + ft_strlen(n)) <= len)
				return ((char *)mark);
		}
		index++;
	}
	return (NULL);
}
