/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 10:55:43 by claire            #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*fill(unsigned int n, char *str, int size)
{
	str[size] = '\0';
	while (--size + 1)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char		*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = size(n);
	if ((str = ft_wrmalloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	fill(n, str, len);
	return (str);
}
