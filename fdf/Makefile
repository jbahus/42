# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/01 19:23:58 by jbahus            #+#    #+#              #
#    Updated: 2015/01/15 17:57:18 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c get_next_line.c error.c fdf.c draw.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft/

MLX_DIR = ./minilibx_macos/

MLX = -L/usr/X11/lib -lmlx -lXext -lX11

FRAM = -framework OpenGL -framework AppKit

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@#osascript -e 'say "Welcome to the Makefile. you have select the command, all. waiting for the process."'
	@cd $(LIB_DIR); $(MAKE) -f Makefile
	@#osascript -e 'say"lib f t create."'
	@#@cd $(MLX_DIR); $(MAKE) -f Makefile
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB_DIR)libft.a $(MLX)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " | create |"
	@echo " |  ./fdf |"
	@echo " '--------'"
	@#osascript -e 'say"Program f d f create. Command finish."'
	
clean:
	@$(DEL) $(OBJ)
	@#@cd $(MLX_DIR); $(MAKE) clean -f Makefile
	@cd $(LIB_DIR); $(MAKE) clean -f Makefile

fclean: clean
	@$(DEL) $(NAME)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " |  ./fdf |"
	@echo " | delete |"
	@echo " '--------'"
	@cd $(LIB_DIR); $(MAKE) fclean -f Makefile

re: fclean all