/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:59:01 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/26 13:30:55 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/include/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct		s_fill
{
	const char		*orig_string;
	char			*copy;
	int				len;
	size_t			i;
	char			conv;
	char			*conv_list;
	char			*arg_list;
	char			*args;
	long int		val_precision;
	long int		val_width;
	char			*check;
	int				backslash_0;
}					t_fill;
int					ft_printf(const char *format, ...);
int					ft_parse(t_fill *tool, va_list arg);
void				ft_sort(t_fill *tool, va_list arg);
void				ft_get_conv(t_fill *tool);
void				ft_find_conv(t_fill *tool);
void				ft_get_width(t_fill *tool, va_list arg);
void				ft_get_prec(t_fill *tool, va_list arg);
char				*ft_apply_minus(char *conversion, t_fill *tool);
char				*ft_apply_reg_width(char *conversion, t_fill *tool);
char				*ft_apply_zero(char *conversion, t_fill *tool);
void				ft_convert(t_fill *tool, va_list arg);
char				*ft_apply_d(t_fill *tool, va_list arg);
t_fill				*ft_init(t_fill *tool);
t_fill				*ft_reinit(t_fill *tool);
char				*ft_apply_prec_num(char *conversion, t_fill *tool);
char				*ft_apply_c(va_list arg, t_fill *tool);
char				*ft_apply_s(t_fill *tool, va_list arg);
char				*ft_apply_prec_s(char *s, t_fill *tool);
char				*ft_apply_x(t_fill *tool, va_list arg);
char				*ft_apply_p(t_fill *tool, va_list arg);
char				*ft_apply_u(t_fill *tool, va_list arg);
int					ft_check_zero(t_fill *tool);
void				ft_tool_conv(t_fill *tool, char *conversion);
void				ft_check_args(t_fill *tool, va_list arg);
void				ft_too_many_args(t_fill *tool, va_list arg);
char				*ft_get_string(t_fill *tool, va_list arg);
void				ft_free_tool(t_fill *tool);
void				ft_display(char *conversion, t_fill *tool);
char				*ft_apply_pcent(t_fill *tool);
#endif
