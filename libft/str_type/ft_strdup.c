/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:27:53 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(src);
	if (!(copy = ft_wrmalloc((i + 1) * sizeof(char))))
		return (NULL);
	while (src[j] != '\0')
	{
		copy[j] = src[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
