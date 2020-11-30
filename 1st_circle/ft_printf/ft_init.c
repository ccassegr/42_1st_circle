/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 12:43:51 by claire            #+#    #+#             */
/*   Updated: 2020/11/30 11:02:00 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_fill	*ft_init(t_fill *tool)
{
	tool->copy = (char *)tool->orig_string;
	tool->len = 0;
	tool->i = 0;
	tool->conv_list = "cspdiuxX%";
	tool->arg_list = "-.0*";
	tool->check = NULL;
	tool->val_width = 0;
	tool->val_precision = 0;
	tool->conv = 0;
	tool->len = 0;
	tool->backslash_0 = 0;
	return (tool);
}

t_fill	*ft_reinit(t_fill *tool)
{
	tool->i = 0;
	tool->args = NULL;
	tool->val_precision = 0;
	tool->val_width = 0;
	tool->conv = 0;
	tool->check = NULL;
	tool->backslash_0 = 0;
	return (tool);
}
