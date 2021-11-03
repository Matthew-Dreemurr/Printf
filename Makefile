# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/11/02 17:26:06 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #

CC    = gcc
CFLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_DIR = src/
OBJ_DIR = obj/

SRC = \
       ft_printf.c
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
SRCS  = $(addprefix $(SRC_DIR), $(SRC))

# _.-=+=-._.-=+=-._[ Tools Var ]_.-=+=-._.-=+=-._ #

BRANCH = master

# _.-=+=-._.-=+=-._[ Rules ]_.-=+=-._.-=+=-._ #

.PHONY: all, clean, fclean, re, bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	@printf "\033[32;1m[================ Linked OK =================]\033[32;0m\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -I include -c $< -o $@
	@printf "\033[32;1m[================ Compile OK =================]\033[32;0m\n"

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
