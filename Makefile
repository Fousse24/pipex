# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 15:31:26 by sfournie          #+#    #+#              #
#    Updated: 2021/09/09 16:49:06 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra

NAME	= pipex

DIR_S	= src
DIR_I	= include

_SRC	= ft_pipex.c ft_error.c ft_commands.c ft_file.c \
		ft_string.c
SRC		= $(patsubst %,$(DIR_S)/%,$(_SRC))

$(NAME)	: $(SRC) $(DIR_I)
		$(CC) $(CFLAGS) -I$(DIR_I)/ $(SRC) -o $(NAME)

all		: $(NAME)

clean	: 

fclean	: 
		rm -f pipex

.PHONY	: all clean fclean $(NAME)