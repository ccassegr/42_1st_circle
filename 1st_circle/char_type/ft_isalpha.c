/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 08:29:25 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:29:31 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

static int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

int			ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
		return (1);
	else
		return (0);
}
