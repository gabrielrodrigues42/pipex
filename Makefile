# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 22:25:32 by gandrade          #+#    #+#              #
#    Updated: 2021/12/12 22:39:33 by gandrade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
MKDIR = mkdir -p $(@D)

INCLUDE_DIR = ./include
INCLUDE = $(addprefix -I, $(INCLUDE_DIR))

SRC_DIR = ./src
OBJ_DIR = ./obj
UTILS_DIR = utils

SRC_FILES = main.c \
            pipex.c \
            init_vars.c \
            get_cmd_list.c \
            get_cmd_path.c \
            get_env_path.c \
            handle_child.c \
            handle_parent.c \
            print_error.c \
            clear_exit.c \
            $(UTILS) \

UTILS_FILES = ft_strncmp.c \
              ft_strcmp.c \
              ft_split.c \
              ft_strdup.c \
              ft_substr.c \
              ft_strjoin.c \
              ft_strclear2.c \
              ft_strlen.c \
              ft_putendl_fd.c \
              ft_strtrim.c \

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

.PHONY: all clean fclean re
