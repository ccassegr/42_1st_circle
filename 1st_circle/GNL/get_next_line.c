/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:36:55 by ccassegr          #+#    #+#             */
/*   Updated: 2020/08/31 17:23:31 by claire           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *str, char *buf, int fd, int *result_read)
{
	int i;

	i = BUFFER_SIZE;
	while (!(ft_strchr(str, '\n')) && *result_read)
	{
		if (!(buf = malloc(i * sizeof(char) + 1)))
			return (NULL);
		if ((*result_read = read(fd, buf, i)) < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		if (*result_read)
		{
			buf[*result_read] = '\0';
			str = ft_strjoin(str, buf);
		}
		free(buf);
	}
	return (str);
}

void	ft_newline(char **str, char **line)
{
	char *after;
	char *newline;
	char *tmp;

	tmp = NULL;
	after = ft_strchr(*str, '\n');
	if (after)
	{
		newline = ft_strduplen(*str, (ft_strlen(*str) - ft_strlen(after)));
		tmp = ft_strduplen(after, ft_strlen(after));
	}
	else
		newline = ft_strduplen(*str, ft_strlen(*str));
	*line = newline;
	free(*str);
	*str = tmp;
}

int		get_next_line(int fd, char **line)
{
	static char *str = NULL;
	char		*buf;
	int			result;

	result = 1;
	buf = NULL;
	*line = NULL;
	if (!str)
		str = ft_strduplen(str, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || !(str = ft_read(str, buf, fd, &result)))
	{
		if (str)
			free(str);
		return (-1);
	}
	ft_newline(&str, line);
	if (result != 0)
		return (1);
	return (0);
}
