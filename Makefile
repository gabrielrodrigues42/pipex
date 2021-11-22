# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 22:25:32 by gandrade          #+#    #+#              #
#    Updated: 2021/11/21 19:47:14 by gandrade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang
CFLAGS = -Wall -Wextra -Werror
SAN = -fsanitize=address
DEBUG = -g3

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
              ft_split.c \
              ft_strdup.c \
              ft_substr.c \
              ft_strclear.c \
              ft_strlen.c \

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

debug:
	$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re norm san debug
