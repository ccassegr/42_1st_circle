/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:46:53 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	min_number(unsigned int min_n, int fd)
{
	if (min_n > 0)
	{
		min_number(min_n / 10, fd);
		ft_putchar_fd(min_n % 10 + '0', fd);
	}
}

static void	actual_putnbr(int n, int fd)
{
	unsigned int min_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		min_n = n;
		min_number(min_n, fd);
	}
	else if (n > 0)
	{
		actual_putnbr(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd(n + '0', fd);
	else
		actual_putnbr(n, fd);
}
