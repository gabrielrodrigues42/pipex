# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 22:25:32 by gandrade          #+#    #+#              #
#    Updated: 2021/11/14 13:41:52 by gandrade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang
CFLAGS = -Wall -Wextra -Werror
SAN = -g3 -fsanitize=address

RM = rm -rf
MKDIR = mkdir -p

INCLUDE_DIR = ./include
INCLUDE = $(addprefix -I, $(INCLUDE_DIR))

SRC_DIR = ./src
OBJ_DIR = ./obj

SRC_FILES = main.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(OBJ_DIR)
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
	norminette $(INCLUDE_DIR) $(SRC_DIR)

san:
	$(CC) $(CFLAGS) $(SAN) $(OBJ) $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re norm san
