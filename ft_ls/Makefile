# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/19 20:06:58 by jbahus            #+#    #+#              #
#    Updated: 2015/02/19 20:14:37 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c error.c ft_ls.c get_info.c ft_a.c ft_t.c get_stats.c trie_time.c ft_r.c ft_bigr.c ##ft_l.c

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