# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mroux <mroux@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/27 17:07:21 by mroux             #+#    #+#              #
#    Updated: 2014/05/08 06:41:07 by mroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c read.c ligne.c calc.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;34m"
	@echo "__________________________________"
	@echo "|                                |"
	@echo "|  _|_|_|_|  _|_|_|    _|_|_|_|  |"
	@echo "|  _|        _|    _|  _|        |"
	@echo "|  _|_|_|    _|    _|  _|_|_|    |"
	@echo "|  _|        _|    _|  _|        |"
	@echo "|  _|        _|_|_|    _|        |"
	@echo "|                                |"
	@echo "|________________________________|"
	@echo "By mroux"

	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB) -L /usr/X11/lib -I /usr/X11/include/ -lmlx -lXext -lX11

clean:
	@rm -rf $(OBJ)
	@make clean -C libft
	@echo "\033[1;32mClean \033[1;35m √"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo "\033[1;32mFclean \033[1;35m √"

re: fclean all

.PHONY: re clean fclean
