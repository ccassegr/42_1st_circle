/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:55:00 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = b;
	while (i < len)
	{
		mem[i] = c;
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
