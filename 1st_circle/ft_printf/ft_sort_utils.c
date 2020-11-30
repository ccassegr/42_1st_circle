/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 18:29:37 by aviscogl          #+#    #+#             */
/*   Updated: 2020/11/30 11:02:00 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_find_conv(t_fill *tool)
{
	while (tool->copy[tool->i] != '%')
	{
		ft_putchar_fd(tool->copy[tool->i], 1);
		tool->i++;
		tool->len++;
	}
	tool->i++;
	ft_get_conv(tool);
	tool->copy = ft_substr(tool->copy, tool->i, ft_strlen(tool->copy));
	return ;
}

void	ft_get_conv(t_fill *tool)
{
	int		i2;
	char	c;

	i2 = tool->i;
	while ((c = ft_strcmp(tool->conv_list, tool->copy[i2])) == 0)
		i2++;
	tool->conv = c;
	tool->args = ft_substr(tool->copy, tool->i, ((i2 - tool->i) + 1));
	tool->i = i2 + 1;
	return ;
}

void	ft_get_width(t_fill *tool, va_list arg)
{
	int i;

	i = 0;
	if (tool->args[i] == '-' || tool->args[i] == '0')
		i++;
	if (tool->args[i] == '*')
	{
		tool->val_width = va_arg(arg, int);
		return ;
	}
	if (tool->args[i] == '-')
		i++;
	while (tool->args[i] >= '0' && tool->args[i] <= '9')
	{
		tool->val_width = (tool->val_width * 10) + ((tool->args[i]) - 48);
		i++;
	}
	return ;
}

void	ft_get_prec(t_fill *tool, va_list arg)
{
	int i;
	int prec;

	i = 0;
	prec = 0;
	while (tool->args[i] != '.' && tool->args[i] != '\0')
		i++;
	if (tool->args[i] == '.')
		i++;
	if (tool->args[i] == '*')
	{
		prec = va_arg(arg, int);
		tool->val_precision = prec;
		return ;
	}
	while (tool->args[i] >= '0' && tool->args[i] <= '9')
	{
		prec = (prec * 10) + ((tool->args[i]) - 48);
		i++;
	}
	tool->val_precision = prec;
	return ;
}
