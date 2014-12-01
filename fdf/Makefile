# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/01 19:23:58 by jbahus            #+#    #+#              #
#    Updated: 2014/12/01 20:16:58 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ft_read_fd.c main.c fdf.c get_next_line.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft/

MLX_DIR = ./minilibx_macos/

FRAM = -framework OpenGL -framework AppKit

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LIB_DIR); $(MAKE) -f Makefile
	@cd $(MLX_DIR); $(MAKE) -f Makefile
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB_DIR)libft.a $(MLX_DIR)libmlx.a $(FRAM)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " | create |"
	@echo " |  ./fdf |"
	@echo " '--------'"
	
clean:
	@$(DEL) $(OBJ)
	@cd $(MLX_DIR); $(MAKE) clean -f Makefile
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