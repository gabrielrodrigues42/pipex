# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 22:25:32 by gandrade          #+#    #+#              #
#    Updated: 2021/11/20 16:43:10 by gandrade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang
CFLAGS = -Wall -Wextra -Werror
SAN = -g3 -fsanitize=address

RM = rm -rf
MKDIR = mkdir -p $(@D)

INCLUDE_DIR = ./include
INCLUDE = $(addprefix -I, $(INCLUDE_DIR))

SRC_DIR = ./src
OBJ_DIR = ./obj
UTILS_DIR = utils

SRC_FILES = main.c \
            get_path.c \
            $(UTILS) \

UTILS_FILES = ft_strncmp.c \

UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette $(INCLUDE_DIR) $(SRC_DIR)/**

san:
	$(CC) $(CFLAGS) $(SAN) $(OBJ) $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re norm san
