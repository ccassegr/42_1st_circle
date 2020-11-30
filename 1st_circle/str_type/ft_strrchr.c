/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:04:34 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int comp;
	int tmp;

	i = 0;
	comp = 0;
	tmp = 0;
	if (c == 0)
		return (((char*)s) + (ft_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == ((char)c))
		{
			tmp = i;
			comp++;
		}
		i++;
	}
	if (comp != 0)
		return (((char *)s + tmp));
	return (NULL);
}
