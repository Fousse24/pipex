# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 15:31:26 by sfournie          #+#    #+#              #
#    Updated: 2021/09/18 14:28:14 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -g

NAME	= pipex

_LFT	= libft.a
LFT_D	= libft
LFT		= $(LFT_D)/$(_LFT)
LFT_M	= cd $(LFT_D) && make

DIR_S	= src
DIR_O	= obj
DIR_I	= include

MAIN	= $(DIR_S)/ft_pipex.c
_SRC		= ft_error.c ft_commands.c ft_file.c \
			ft_cmd_list.c ft_utils.c ft_split_cmds.c
SRC		= $(patsubst %,$(DIR_S)/%,$(_SRC))
vpath %.c $(DIR_S)

_OBJ	= $(_SRC:.c=.o)
OBJ	= $(patsubst %,$(DIR_O)/%,$(_OBJ))
vpath %.o $(DIR_O)

$(DIR_O)/%.o :  %.c 
	@$(CC) $(CFLAGS)  -I$(DIR_I)/ -I$(LFT_D)/ -c $< -o $@

all		: $(NAME)

$(NAME)	: $(DIR_I) $(LFT) $(SRC) $(DIR_O) $(OBJ) $(MAIN)
		@$(CC) $(CFLAGS) -I$(DIR_I)/ -I$(LFT_D)/ $(LFT) $(MAIN) $(OBJ) -o $(NAME)
		# $(shell echo "Compiling pipex done!")
		# $(shell echo "Executable is : $(NAME)")

$(LFT)	:
		@$(LFT_M) all
		
$(DIR_O):
		@mkdir obj

clean	: 
		@rm -rf $(OBJ)
		@$(LFT_M) clean
		# $(shell echo "Cleaning pipex done!")

fclean	: clean
		@$(LFT_M) fclean
		@rm -rf $(NAME)
		# $(shell echo "Full cleaning pipex done!")
		

re		: fclean all

bonus	: all

.PHONY	: all re clean fclean bonus