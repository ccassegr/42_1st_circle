/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:15:01 by claire            #+#    #+#             */
/*   Updated: 2020/11/25 16:17:07 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libftprintf.h"

char	*ft_apply_s(t_fill *tool, va_list arg)
{
	char *s;

	s = va_arg(arg, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	if (!ft_strncmp(s, "", ft_strlen(s)))
		return (s);
	if ((tool->val_precision > 0) || ft_strchr(tool->args, '.'))
		s = ft_apply_prec_s(s, tool);
	return (s);
}
