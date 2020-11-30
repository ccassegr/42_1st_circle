/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:52:35 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/30 11:02:00 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*check_minus(int minus, char *conversion)
{
	if (minus == 1)
		conversion = ft_strjoin("-", conversion);
	return (conversion);
}

char	*ft_fill_part(int nb_zero, char *conversion, int minus)
{
	char *part1;
	char *result;

	result = 0;
	part1 = 0;
	if (!(part1 = ft_wrmalloc((nb_zero + 1) * sizeof(char))))
		return (0);
	ft_memset(part1, '0', nb_zero);
	result = ft_strjoin(part1, conversion);
	result = check_minus(minus, result);
	return (result);
}

char	*ft_apply_prec_num(char *conversion, t_fill *tool)
{
	char	*result;
	char	*part1;
	int		nb_zero;
	int		minus;

	minus = 0;
	part1 = 0;
	if ((unsigned long)tool->val_precision < ft_strlen(conversion))
		return (conversion);
	if (conversion[0] == '-')
	{
		conversion = ft_strtrim(conversion, "-");
		minus++;
	}
	if ((long)ft_strlen(conversion) < tool->val_precision)
	{
		nb_zero = tool->val_precision - (ft_strlen(conversion));
		result = ft_fill_part(nb_zero, conversion, minus);
		return (result);
	}
	check_minus(minus, conversion);
	return (conversion);
}

char	*ft_apply_prec_s(char *s, t_fill *tool)
{
	char	*result;
	int		i;

	i = 0;
	if (tool->val_precision < 0)
		return (s);
	if (!(result = ft_wrmalloc((tool->val_precision + 1) * sizeof(char))))
		return (0);
	while (i < tool->val_precision)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
