/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:17:26 by ccassegr          #+#    #+#             */
/*   Updated: 2020/10/31 16:13:16 by claire           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

int	ft_printf(const char *s, ...)
{
	t_fill	*tool;
	va_list	arg;
	int		len;

	len = 0;
	if (!(tool = (t_fill*)ft_wrmalloc(1 * sizeof(t_fill))))
		return (-1);
	tool->orig_string = s;
	tool = ft_init(tool);
	if (s)
	{
		va_start(arg, s);
		tool->len = ft_parse(tool, arg);
		va_end(arg);
	}
	len = tool->len;
	ft_wrdestroy();
	return (len);
}
