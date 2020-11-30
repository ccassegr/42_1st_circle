/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 07:51:11 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = len - 1;
	if (dst == NULL && src == NULL && len > 0)
		return (dst);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (i >= 0)
		{
			*(((char*)dst) + i) = *(((char*)src) + i);
			i--;
		}
	return (dst);
}
