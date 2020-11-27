/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:13:34 by claire            #+#    #+#             */
/*   Updated: 2020/11/27 11:22:41 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

void	ft_convert(t_fill *tool, va_list arg)
{
	char	*conversion;

	conversion = NULL;
	if (!(tool->check))
	{
		if (tool->conv == 'd' || tool->conv == 'i')
			conversion = ft_apply_d(tool, arg);
		if (tool->conv == 'c')
			conversion = ft_apply_c(arg, tool);
		if (tool->conv == 's')
			conversion = ft_apply_s(tool, arg);
		if (tool->conv == 'x' || tool->conv == 'X')
			conversion = ft_apply_x(tool, arg);
		if (tool->conv == 'p')
			conversion = ft_apply_p(tool, arg);
		if (tool->conv == 'u')
			conversion = ft_apply_u(tool, arg);
		if (tool->conv == '%')
			conversion = ft_apply_pcent(tool);
		if (conversion == NULL)
			conversion = ft_strdup("(null)");
	}
	ft_tool_conv(tool, conversion);
	return ;
}

void	ft_tool_conv(t_fill *tool, char *conversion)
{
	printf("val width = %ld\n", tool->val_width);
	if (tool->val_width != 0)
	{
		if (ft_strchr(tool->args, '-'))
			conversion = ft_apply_minus(conversion, tool);
		else if (ft_strchr(tool->args, '0') && (!(ft_strchr(tool->args, '-'))))
			conversion = ft_apply_zero(conversion, tool);
		else
			conversion = ft_apply_reg_width(conversion, tool);
	}
	conversion = (tool->check != NULL) ? ft_strdup(tool->check) : conversion;
	tool->len = tool->len + ft_strlen(conversion);
	ft_display(conversion, tool);
	return ;
}

void	ft_display(char *conv, t_fill *tool)
{
	int nb;
	int i;

	i = 0;
	nb = tool->val_width;
	if (tool->conv == 'c' && tool->backslash_0 > 0)
	{
		if (nb == 0)
			ft_putchar_fd('\0', 1);
		else if (tool->args[0] == '-')
		{
			ft_putchar_fd('\0', 1);
			ft_putstr_fd(conv, 1);
		}
		else
		{
			ft_putstr_fd(conv, 1);
			ft_putchar_fd('\0', 1);
		}
	}
	else
		ft_putstr_fd(conv, 1);
	return ;
}
