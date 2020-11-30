/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:22:42 by aviscogl          #+#    #+#             */
/*   Updated: 2020/11/30 11:02:00 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse(t_fill *tool, va_list arg)
{
	if (ft_strcmp((char *)tool->orig_string, '%') == 0)
	{
		ft_putstr_fd((char *)tool->orig_string, 1);
		tool->len = ft_strlen(tool->orig_string);
		return (tool->len);
	}
	else
	{
		while (ft_strcmp((char *)tool->copy, '%') == '%')
		{
			ft_sort(tool, arg);
			ft_convert(tool, arg);
			tool = ft_reinit(tool);
		}
	}
	ft_putstr_fd((char *)tool->copy, 1);
	tool->len = tool->len + ft_strlen(tool->copy);
	return (tool->len);
}

void	ft_sort(t_fill *tool, va_list arg)
{
	ft_find_conv(tool);
	ft_get_width(tool, arg);
	ft_get_prec(tool, arg);
}
