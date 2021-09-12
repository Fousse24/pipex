# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 15:31:26 by sfournie          #+#    #+#              #
#    Updated: 2021/09/11 20:35:24 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra

NAME	= pipex

_LFT	= libft.a
LFT_D	= libft
LFT		= $(LFT_D)/$(_LFT)
LFT_M	= cd $(LFT_D) && make

DIR_S	= src
DIR_I	= include

_SRC	= ft_pipex.c ft_error.c ft_commands.c ft_file.c \
		ft_cmd_list.c ft_utils.c
SRC		= $(patsubst %,$(DIR_S)/%,$(_SRC))

all		: $(NAME)

$(NAME)	: $(DIR_I) $(LFT) $(SRC) $(DIR_I) 
		$(CC) $(CFLAGS) -I$(DIR_I)/ -I$(LFT_D)/ $(LFT) $(SRC) -o $(NAME)

$(LFT)	:
		$(LFT_M) all

clean	: 
		$(LFT_M) clean

fclean	: clean
		$(LFT_M) fclean
		rm -rf $(NAME)

.PHONY	: all clean fclean $(NAME)