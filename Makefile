# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 17:58:18 by jbahus            #+#    #+#              #
#    Updated: 2014/11/11 22:30:54 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME =	ft_bzero.c
			ft_memset.c
			ft_memcpy.c
			ft_memccpy.c
			ft_memmove.c
			ft_memchr.c
			ft_memcmp.c
			ft_strdup.c
			ft_strcpy.c
			ft_strncpy.c
			ft_strcat.c
			ft_strncat.c
			ft_strchr.c
			ft_strrchr.c
			ft_strstr.c
			ft_strnstr.c
			ft_strlcat.c
			ft_strlen.c
			ft_strcmp.c
			ft_strncmp.c
			ft_atoi.c
			ft_isalpha.c
			ft_isdigit.c
			ft_isalnum.c
			ft_isascii.c
			ft_isprint.c
			ft_toupper.c
			ft_tolower.c
			ft_memalloc.c
			ft_memdel.c
			ft_strnew.c
			ft_strdel.c
			ft_strclr.c
			ft_striter.c
			ft_striteri.c
			ft_strmap.c
			ft_strmapi.c
			ft_strequ.c
			ft_strnequ.c
			ft_strsub.c
			ft_strjoin.c
			ft_strtrim.c
			ft_strsplit.c
			ft_itoa.c
			ft_putchar.c
			ft_putstr.c
			ft_putendl.c
			ft_putnbr.c
			ft_putchar_fd.c
			ft_putstr_fd.c
			ft_putendl_fd.c
			ft_putnbr_fd.c
			ft_isspace.c

OBJ_PATH = ./obj/

INC_PATH = ./include/

LIB_PATH = ./lib/
LIB_NAME = libft.a

NAME = a.out

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L$(LIB_PATH) -I$(INC_PATH) -o $(NAME) $(LIB) $(OBJ)
	$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -L$(LIB_PATH) -I$(INC_PATH) -o $@ -c $<
	@mkdir $(OBJ_PATH) 2> /dev/null || echo ''> /dev/null

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
