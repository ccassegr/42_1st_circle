/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:39:54 by claire            #+#    #+#             */
/*   Updated: 2020/11/26 14:35:04 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

char	*ft_apply_p(t_fill *tool, va_list arg)
{
	unsigned long int		ad_p;
	char					*result;
	char					*base;

	base = "0123456789abcdef";
	ad_p = va_arg(arg, unsigned long);
	result = ft_itoa_base_ptr(ad_p, base);
	if (ad_p == 0)
		return ("0x0");
	if (ft_strchr(tool->args, '0') && tool->val_precision != 0)
	{
		tool->len = tool->len + 2;
		ft_putstr_fd("0x", 1);
	}
	else
		result = ft_strjoin("0x", result);
	return (result);
}
