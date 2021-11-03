# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/11/03 14:34:46 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #

CC    = gcc
CFLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_DIR = src/
OBJ_DIR = obj/

SRCS = \
		src/ft_printf.c \
		src/libft/ft_putstr_fd.c

OBJS = $(SRCS:.c=.o)

# _.-=+=-._.-=+=-._[ Tools Var ]_.-=+=-._.-=+=-._ #

BRANCH = main

# _.-=+=-._.-=+=-._[ Rules ]_.-=+=-._.-=+=-._ #

.PHONY: all, clean, fclean, re, bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@printf "\033[32;1m[================ Linked OK =================]\033[32;0m\n"

%.o: %.c
	$(CC) $(CFLAG) -I include -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all


# _.-=+=-._.-=+=-._[ Tools ]_.-=+=-._.-=+=-._ #

.PHONY: c, cf, r, git, fgit

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
