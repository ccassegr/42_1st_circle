/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:59:06 by claire            #+#    #+#             */
/*   Updated: 2020/11/26 13:12:35 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

char	*ft_apply_d(t_fill *tool, va_list arg)
{
	int		d;
	char	*conversion;

	d = va_arg(arg, int);
	conversion = ft_itoa(d);
	if (tool->val_precision == 0 && ft_strchr(tool->args, '.') && d == 0)
		return ("");
	if (tool->val_precision > 0)
		conversion = ft_apply_prec_num(conversion, tool);
	return (conversion);
}

char	*ft_apply_u(t_fill *tool, va_list arg)
{
	long long int	u;
	char			*conversion;

	u = va_arg(arg, unsigned int);
	conversion = ft_utoa(u);
	if (u == 0 && tool->val_precision == 0 && (ft_strchr(tool->args, '.')\
				!= NULL))
		return ("");
	if (tool->val_precision > 0)
		conversion = ft_apply_prec_num(conversion, tool);
	return (conversion);
}
