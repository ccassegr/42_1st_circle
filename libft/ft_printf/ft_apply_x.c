/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:11:18 by claire            #+#    #+#             */
/*   Updated: 2020/11/30 11:02:00 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_apply_x(t_fill *tool, va_list arg)
{
	unsigned int	value;
	char			*result;
	char			*x_base;
	char			*xmaj_base;

	x_base = "0123456789abcdef";
	xmaj_base = "0123456789ABCDEF";
	value = va_arg(arg, unsigned int);
	if (tool->conv == 'x')
		result = ft_itoa_base(value, x_base);
	if (tool->conv == 'X')
		result = ft_itoa_base(value, xmaj_base);
	if (tool->val_precision >\
	(long)ft_strlen(result) && tool->val_precision > 0)
		result = ft_apply_prec_num(result, tool);
	if (tool->val_precision == 0 && ft_strchr(tool->args, '.') && value == 0)
		result = ft_strdup("");
	return (result);
}
