/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:03:51 by claire            #+#    #+#             */
/*   Updated: 2020/11/30 11:02:00 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_apply_minus(char *conversion, t_fill *tool)
{
	int		i;
	char	*res1;
	char	*res2;
	int		val;

	val = (tool->val_width > 0) ? tool->val_width : tool->val_width * -1;
	i = val - ft_strlen(conversion);
	if (tool->conv == 'c' && conversion[0] == '\0')
		i--;
	if (i > 0)
	{
		if (!(res1 = ft_wrmalloc((i + 1) * sizeof(char))))
			return (0);
		ft_memset(res1, ' ', i);
		res2 = ft_strjoin(conversion, res1);
		return (res2);
	}
	return (conversion);
}

char	*ft_apply_reg_width(char *conversion, t_fill *tool)
{
	int		i;
	char	*res1;
	char	*res2;
	int		val;

	printf("val width = %ld\n", tool->val_width);
	val = (tool->val_width > 0) ? tool->val_width : tool->val_width * -1;
	if (tool->val_width < 0 || tool->args[0] == '-')
		conversion = ft_apply_minus(conversion, tool);
	if (conversion[0] == 0 && conversion[1] == 0 && tool->conv == 'c')
		val--;
	i = val - ft_strlen(conversion);
	if (i > 0)
	{
		if (!(res1 = ft_wrmalloc((i + 1) * sizeof(char))))
			return (0);
		ft_memset(res1, ' ', i);
		res2 = ft_strjoin(res1, conversion);
		return (res2);
	}
	return (conversion);
}

char	*ft_apply_zero(char *conversion, t_fill *tool)
{
	int i;
	int check;

	i = 0;
	check = ft_check_zero(tool);
	if (tool->conv == 'p' && check == 0)
		tool->val_width = (tool->val_width > 0) ? tool->val_width - 2 : \
		tool->val_width + 2;
	if (ft_strnstr(conversion, "(nil)", ft_strlen(conversion)))
	{
		tool->val_width += 2;
		conversion = ft_apply_reg_width(conversion, tool);
		return (conversion);
	}
	conversion = ft_apply_reg_width(conversion, tool);
	if (check > 0)
		return (conversion);
	if (ft_strchr(conversion, '-') && (tool->conv == 'i' || tool->conv == 'd'))
		conversion[i++] = '-';
	while (conversion[i] == ' ' || conversion[i] == '-')
	{
		conversion[i] = '0';
		i++;
	}
	return (conversion);
}

int		ft_check_zero(t_fill *tool)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (tool->args[i] != '0')
		i++;
	if (i > 0)
		result++;
	if (tool->val_precision == 0 && ft_strchr(tool->args, '.'))
		result++;
	if (tool->conv == 'c')
		result++;
	if (tool->val_width > tool->val_precision && ft_strchr(tool->args, '.'))
		result++;
	return (result);
}
