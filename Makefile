# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claire <claire@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 09:13:57 by ccassegr          #+#    #+#              #
#    Updated: 2020/11/27 17:44:52 by ccassegr         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_parse.c ft_printf.c ft_sort_utils.c ft_apply_num.c ft_apply_width.c\
				ft_convert.c ft_init.c ft_apply_prec.c ft_apply_c.c ft_apply_s.c ft_apply_x.c\
				ft_apply_p.c ft_apply_pcent.c

PATH_INC	=	include
PATH_LIBFT	=	libft

OBJS		=	$(SRCS:.c=.o)
INCS		=	$(addprefix $(PATH_INC)/, libftprintf.h)

CC			=	clang
FLAGS		=	-Wall -Wextra -Werror -I$(PATH_LIBFT)/$(PATH_INC) -I$(PATH_INC)

CLEAN		=	make clean

GREEN		=	\x1b[32;01m
NORMAL		=	\033[0m
all: init $(NAME)

init:
	@ make -C $(PATH_LIBFT)

$(NAME): $(OBJS) $(INCS)
	@ echo "$(NORMAL)Compiling..."
	@ ar rcs $(NAME)  $(OBJS)
	@ echo "$(GREEN)Ft_printf compiled."

%.o: %.c $(INCS)
	@ $(CC) $(FLAGS) -I $(PATH_INC) -c -o $@ $<

clean:
	@ rm -f $(OBJS)
	@ make -C $(PATH_LIBFT) clean

fclean: clean
	@ rm -f libftprintf.a
	@ make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: re fclean clean all
