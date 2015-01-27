# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 15:35:10 by jbahus            #+#    #+#              #
#    Updated: 2015/01/27 17:15:39 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c error.c ft_ls.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft/

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@cd $(LIB_DIR); $(MAKE) -f Makefile
	@gcc $(FLAG) -c $(SRC)
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB_DIR)libft.a
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " | create |"
	@echo " |./ft_ls |"
	@echo " '--------'"

clean:
	@$(DEL) $(OBJ)
	@cd $(LIB_DIR); $(MAKE) clean -f Makefile

fclean: clean
	@$(DEL) $(NAME)
	@echo "\|/        "
	@echo "-o------.  "
	@echo "/|\     |\ "
	@echo " |      '-|"
	@echo " |./ft_ls |"
	@echo " | delete |"
	@echo " '--------'"
	@cd $(LIB_DIR); $(MAKE) fclean -f Makefile

re: fclean all