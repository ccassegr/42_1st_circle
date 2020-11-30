# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 13:07:41 by ccassegr          #+#    #+#              #
#    Updated: 2020/11/30 11:04:19 by ccassegr         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= 1st_circle.a
#dir name
PATH_INC		=	include
#dirs srcs
SRCS_CHARTYPE	=	$(addprefix ./char_type/, ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isascii.c)
SRCS_LSTTYPE	=	$(addprefix ./lst_type/, ft_lstadd_back.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c)
SRCS_FDTYPE		=	$(addprefix ./fd_type/, ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c)
SRCS_MEMTYPE	=	$(addprefix ./mem_type/, ft_bzero.c ft_calloc.c ft_memccpy.c ft_memcpy.c ft_memset.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_wrmalloc.c)
SRCS_NBRTYPE	=	$(addprefix ./nbr_type/, ft_atoi.c ft_itoa.c ft_itoa_base.c ft_itoa_base_ptr.c ft_utoa.c)
SRCS_STRTYPE	=	$(addprefix ./str_type/, ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c ft_substr.c ft_split.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_strcmp.c ft_strcpy.c)
SRCS_GNL		=	$(addprefix ./GNL/, get_next_line.c get_next_line_utils.c)
SRCS_PF			=	$(addprefix ./ft_printf/, ft_apply_c.c ft_apply_num.c ft_apply_p.c ft_apply_pcent.c ft_apply_prec.c ft_apply_s.c ft_apply_width.c ft_apply_width.c ft_apply_x.c ft_convert.c ft_init.c ft_parse.c ft_printf.c ft_sort_utils.c)
#dependencies
SRCS	= $(SRCS_CHARTYPE) $(SRCS_LSTTYPE) $(SRCS_FDTYPE) $(SRCS_MEMTYPE) $(SRCS_NBRTYPE) $(SRCS_STRTYPE) $(SRCS_GNL) $(SRCS_PF)
OBJS	= $(SRCS:.c=.o)
INCS	= $(addprefix $(PATH_INC)/, libft.h get_next_line.h libftprintf.h)

#compilation
CC		= clang
FLAGS	= -Wall -Wextra -Werror

#colors
GREEN	= \x1b[32;01m
NORMAL	= \033[0m

#rules
all : $(NAME)

$(NAME) : $(OBJS) $(INCS)
	@ echo "Compiling..."
	@ ar rcs $(NAME) $(OBJS)
	@ echo "$(GREEN)1st circle compiled."

%.o: %.c $(INCS)
	@ $(CC) $(FLAGS) -I $(PATH_INC) -c -o $@ $<

clean : 
	@ rm -f  $(OBJS)

fclean : clean
	@ rm -f $(NAME)

re : fclean all

.PHONY : re fclean clean all bonus
