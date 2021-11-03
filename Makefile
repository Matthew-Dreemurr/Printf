# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/11/03 17:11:12 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #

CC		= gcc
DEBUG	= -fsanitize=address
CFLAG	= -Wall -Wextra -Werror $(DEBUG)

NAME	=libftprintf.a

# _.-=+=-._.-=+=-._[ Source & Bin ]_.-=+=-._.-=+=-._ #

SRC_DIR = src/
OBJ_DIR = obj/

# _.-=[ Ft_printf ]=-._ #

SRCS	= \
		src/ft_printf.c \
		src/arg_manager.c

# _.-=[ Libft ]=-._ #
SRCS	+= \
		src/libft/ft_putstr.c \
		src/libft/ft_putchar.c

SRC		= $(notdir $(SRCS))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

VPATH	= $(SRC_DIR) $(OBJ_DIR) $(shell find $(SRC_DIR) -type d)

# _.-=+=-._.-=+=-._[ Rules ]_.-=+=-._.-=+=-._ #

.PHONY: all, clean, fclean, re, bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@printf "\033[32;1m[================ Linked OK =================]\033[32;0m\n"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -I include -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

# _.-=+=-._.-=+=-._[ Dev Tools #TODO REMOVE ]_.-=+=-._.-=+=-._ #

.PHONY: c, cf, r, git, fgit, m, mor, mft, exe

BRANCH	= main

exe:
	echo "\033[1J"
	./a.out

m: $(NAME)
	$(CC) $(CFLAG) $(NAME) main.c

mor:
	gcc main.c $(CFLAG)  -D OR_
mft: $(NAME)
	gcc main.c $(NAME) $(CFLAG) -D FT_

c: clean

cf: fclear

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
