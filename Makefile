# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fanivia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 17:50:50 by fanivia           #+#    #+#              #
#    Updated: 2020/11/13 17:50:52 by fanivia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NASM		=	nasm -fmacho64

HEADER_DIR	=	header/
HEADER_LIST	=	libasm.h

MAIN_DIR	=	main/
MAIN_LIST	=	main.c

SRCS_DIR	=	srcs/
SRCS_LIST	=	ft_strlen.s ft_strcpy.s ft_strcmp.s	ft_write.s ft_read.s\
				ft_strdup.s

HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))
MAIN_SRC	=	$(addprefix $(MAIN_DIR), $(MAIN_LIST))
MAIN_OBJ	=	$(patsubst %.s, %.o, $(MAIN_SRC))
SOURCE		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJ			=	$(patsubst %.s, %.o, $(SOURCE))

.PHONY:		all clean fclean re test

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			ar rcs $(NAME) $?
			ranlib $(NAME)

%.o: %.s $(HEADER_DIR)/libasm.h
		$(NASM) -s $< -o $@

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -f $(NAME) ./a.out file

re:	fclean all

test:	$(NAME)
		$(CC) $(CFLAGS) -L. -I$(HEADER_DIR) -lasm $(MAIN_OBJ)
		./a.out