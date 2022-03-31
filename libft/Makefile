# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncathy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:54:04 by ncathy            #+#    #+#              #
#    Updated: 2021/10/21 11:54:08 by ncathy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c		ft_bzero.c		ft_isalnum.c\
			ft_isalpha.c	ft_isascii.c	ft_isdigit.c\
			ft_isprint.c	ft_memchr.c		ft_memcmp.c\
			ft_memset.c		ft_memcpy.c		ft_strlcpy.c\
			ft_strchr.c		ft_strncmp.c	ft_memmove.c\
			ft_strlen.c		ft_strlcat.c	ft_strrchr.c\
			ft_tolower.c	ft_toupper.c	ft_strnstr.c\
			ft_strdup.c		ft_calloc.c		ft_substr.c\
			ft_strjoin.c	ft_striteri.c	ft_strmapi.c\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
			ft_putnbr_fd.c	ft_strtrim.c	ft_itoa.c\
			ft_split.c\

HEADER	=	libft.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all 	:	$(NAME)

$(NAME)	: 	$(OBJ) $(HEADER)
	ar	rcs $(NAME) $?

%.o	: %.c	$(HEADER)
	$(CC)	$(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all
