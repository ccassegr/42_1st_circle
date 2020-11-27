/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:01:53 by claire            #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base_ptr(unsigned long value, char *base)
{
	int						count;
	unsigned long			tmp;
	char					*res;
	unsigned int			base_length;

	count = 0;
	base_length = ft_strlen(base);
	tmp = value;
	while (tmp >= base_length && (tmp /= base_length))
		count++;
	tmp = value;
	count++;
	if (!(res = (char*)ft_wrmalloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = base[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = base[tmp % base_length];
	return (res);
}
