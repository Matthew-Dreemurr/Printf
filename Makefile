# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/11/08 15:45:14 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #

CC		= gcc
FSANI	= -fsanitize=address
DEBUG	= -g
WERROR	= -Wall -Wextra -Werror
CFLAG	= $(WERROR) $(DEBUG) $(FSANI)

NAME	=libftprintf.a

# _.-=+=-._.-=+=-._[ Source & Bin ]_.-=+=-._.-=+=-._ #

SRC_DIR = src/
OBJ_DIR = obj/

# _.-=[ src/ ]=-._ #

SRCS	= \
		src/ft_printf.c \
		src/arg_manager.c \
		src/conv_char.c \
		src/conv_ptr.c \
		src/conv_digit.c \
		src/conv_char.c \
		src/conv_utils.c \
		src/flag_padding.c \
		src/flag_prefix.c

# _.-=[ src/libft ]=-._ #
SRCS	+= \
		src/libft/ft_putstr.c \
		src/libft/ft_putchar.c \
		src/libft/putchar_ret_int.c \
		src/libft/putstr_ret_int.c \
		src/libft/ft_isdigit.c \
		src/libft/ft_atoi.c

SRC		= $(notdir $(SRCS))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

VPATH	= $(SRC_DIR) $(OBJ_DIR) $(shell find $(SRC_DIR) -type d)

# _.-=+=-._.-=+=-._[ Rules ]_.-=+=-._.-=+=-._ #

.PHONY: all, clean, fclean, re, bonus

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	@ar -rcs $(NAME) $(OBJS)
	@printf "\033[32;1m[================ Linked OK =================]\033[32;0m\n"

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAG) -I include -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@printf "\033[31;1m[Remove *.o]\033[32;0m\n"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@printf "\033[31;1m[Remove $(OBJ_DIR)]\033[32;0m\n"
	@printf "\033[31;1m[Remove $(NAME)]\033[32;0m\n"

re: fclean all

# _.-=+=-._.-=+=-._[ Dev Tools #TODO REMOVE ]_.-=+=-._.-=+=-._ #

.PHONY: c, cf, r, git, fgit, m, mor, mft, exe

BRANCH	= main

exe:
	@echo "\033[1J"
	@./a.out

m: $(NAME)
	@$(CC) $(CFLAG) $(NAME) main.c

mor:
	@gcc main.c  -D OR_
mft: $(NAME)
	@gcc $(CFLAG) main.c $(NAME)  -D FT_

c: clean

fc: fclear

r: re

git:
	@git pull
	@-git add .
	@git commit -am "Makefile push `date +'%Y-%m-%d %H:%M:%S'`"
	@-git push

fgit:
	@printf "\033[31;1m ======== /!\\ Hard reset to the preview commit ? /!\\ ======== \033[0m\n"
	@while true; do read -p "continue [y/N] ? " resp; if [[ $$resp =~ ^[Yy]$$ ]]; then exit 0; else exit 1; fi; done
	@git fetch --all
	@git reset --hard $(BRANCH)
	@git clean -f
