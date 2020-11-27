/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 10:41:18 by claire            #+#    #+#             */
/*   Updated: 2020/11/26 13:11:17 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

char	*ft_apply_c(va_list arg, t_fill *tool)
{
	char c;
	char *ret;

	c = va_arg(arg, unsigned int);
	if (!(ret = ft_wrmalloc(2 * sizeof(char))))
		return (0);
	ft_memset(ret, c, 1);
	if (c == '\0')
	{
		ret[0] = '\0';
		tool->len++;
		tool->backslash_0++;
	}
	return (ret);
}
