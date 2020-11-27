/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:35:18 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && ((char)c) != *(((char*)src) + i))
	{
		*(((char*)dst) + i) = *(((char*)src) + i);
		i++;
	}
	if (((char)c) == *(((char*)src) + i))
	{
		*(((char*)dst) + i) = *(((char*)src) + i);
		i++;
		return (dst + i);
	}
	else
		return (NULL);
}
