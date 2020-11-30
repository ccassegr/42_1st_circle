/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_pcent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:51:25 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/30 11:02:00 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_apply_pcent(t_fill *tool)
{
	char *res;

	res = "%";
	if ((tool->val_precision > 0 || ft_strchr(tool->args, '.'))\
			&& tool->val_precision > 0)
		res = ft_apply_prec_s(res, tool);
	return (res);
}
