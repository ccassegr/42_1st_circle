/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_pcent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:51:25 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/26 13:11:54 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

char	*ft_apply_pcent(t_fill *tool)
{
	char *res;

	res = "%";
	if ((tool->val_precision > 0 || ft_strchr(tool->args, '.'))\
			&& tool->val_precision > 0)
		res = ft_apply_prec_s(res, tool);
	return (res);
}
