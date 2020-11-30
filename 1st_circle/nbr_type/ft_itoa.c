/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 07:19:30 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
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

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nb;

	if (n < 0)
	{
		len = size(n) + 1;
		if ((str = ft_wrmalloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		nb = n * -1;
		fill(nb, str, len);
		str[0] = '-';
	}
	else
	{
		len = size(n);
		if ((str = ft_wrmalloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		fill(n, str, len);
	}
	return (str);
}
