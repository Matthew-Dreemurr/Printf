# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/11/11 14:42:35 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #
CC			= gcc

D = 0
WRA = 0

ifeq ($(WRA), 1)
D = 1
INCLUDES		= -I src/libft/includes/debug
endif

ifeq ($(D), 1)
CFLAGS		+= -fsanitize=address -g3
endif


INCLUDES	= -I includes -I src/libft/includes
CFLAGS		= -Wall -Wextra -Werror $(INCLUDES)

NAME		= libftprintf.a

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
src/libft/src/stdio/ft_putstr.c \
src/libft/src/stdio/ft_putchar.c \
src/libft/src/stdio/putchar_ret_int.c \
src/libft/src/stdio/putstr_ret_int.c \
src/libft/src/ctype/ft_isdigit.c \
src/libft/src/stdlib/ft_atoi.c \
src/libft/src/vector/vect_cat.c \
src/libft/src/vector/vect_init.c \
src/libft/src/vector/vect_resize.c

SRC		= $(notdir $(SRCS))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

VPATH	= $(SRC_DIR) $(OBJ_DIR) $(shell find $(SRC_DIR) -type d)

# _.-=+=-._.-=+=-._[ Rules ]_.-=+=-._.-=+=-._ #
.PHONY: all, clean, fclean, re

all: $(NAME)
	@printf "\033[32;1m[== $(NAME) Created ! ==]\033[32;0m\n"
	@if [[ $D = "1" ]]; then printf "\033[31;1m[/!\\ DEBUG ENABLE /!\\]\033[32;0m\n"; fi

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[32;1m$@\033[32;0m\n"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	@printf "\033[32;1m[Create $(OBJ_DIR)]\033[32;0m\n"

$(NAME): $(OBJ_DIR) $(OBJS)
	@printf "\033[32;1m[Compiled /w CFLAGS=$(CFLAGS)]\033[32;0m\n"
	@ar -rcs $(NAME) $(OBJS)
	@printf "\033[32;1m[== Linked OK ==]\033[32;0m\n"
	$(VPATH) =

clean:
	@rm -rf $(OBJS)
	@printf "\033[31;1m[Remove *.o]\033[32;0m\n"
	@rm -rf $(OBJ_DIR)
	@printf "\033[31;1m[Remove $(OBJ_DIR)]\033[32;0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[31;1m[Remove $(NAME)]\033[32;0m\n"

re: fclean all

# _.-=+=-._.-=+=-._[ Dev Tools #TODO REMOVE ]_.-=+=-._.-=+=-._ #
.PHONY: c, cf, r, git, fgit, m, mor, mft, exe

BRANCH	= main

exe:
	@echo "\033[1J"
	@./a.out

m:
	$(CC) $(CFLAG) $(INCLUDES) $(NAME) main.c

mor:
	$(CC) main.c  -D OR_
mft:
	$(CC) $(CFLAG) $(INCLUDES) main.c $(NAME)  -D FT_

c: clean

fc: fclean

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
