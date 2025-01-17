# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 17:17:12 by hmori             #+#    #+#              #
#    Updated: 2025/01/16 21:14:32 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

LEAK = -fsanitize=leak
SEGFA = -fsanitize=address

INCLUDE = include/minitalk.h
CRIENT_SRC_FILES = client.c
SERVER_SRC_FILES = server.c

LIBFT = libft
LIBFTA = $(LIBFT)/libft.a

SRC_DIR = src

OBJ_DIR = obj
CLIENT_OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(CRIENT_SRC_FILES))
SERVER_OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SERVER_SRC_FILES))

CLIENT = client
SERVER = server

all: $(LIBFT) $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIBFTA) $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) $(LIBFTA)

$(SERVER): $(SERVER_OBJS) $(LIBFTA) $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) $(LIBFTA)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft/ bonus

bonus: all

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(CLIENT) $(SERVER)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean bonus re $(LIBFT)

