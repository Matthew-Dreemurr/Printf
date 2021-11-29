# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/11/29 16:55:33 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #
CC			= gcc

D = 0
WRA = 0
WRR = 1
SANI = 0

ifeq ($(WRA), 1)
D = 1
INCLUDES		+= -I src/libft/includes/debug -D WRA
endif

ifeq ($(SANI), 1)
D = 1
CFLAGS += -fsanitize=address 
endif

ifeq ($(D), 1)
CFLAGS		+= -g3
endif

INCLUDES	+= -I includes -I src/libft/includes
CFLAGS		+= $(INCLUDES)
ifeq ($(WRR), 1)
CFLAGS += -Wall -Wextra -Werror
endif

NAME		= libftprintf.a

# _.-=+=-._.-=+=-._[ Source & Bin ]_.-=+=-._.-=+=-._ #
SRC_DIR = src/
OBJ_DIR = obj_printf/

# _.-=[ src/ ]=-._ #
SRCS	= \
ft_printf.c \
arg_manager.c \
conv_char.c \
conv_ptr.c \
conv_digit.c \
conv_char.c \
conv_utils.c

# _.-=[ src/libft ]=-._ #
SRCS	+= \
ft_putstr.c \
ft_putstr_fd.c \
ft_putchar.c \
putchar_ret_int.c \
putstr_ret_int.c \
ft_strchr.c \
strlen_protect.c \
len_chrchr.c \
ft_isdigit.c \
ft_atoi.c \
vect_cat.c \
vect_push.c \
vect_init.c \
vect_resize.c \
ft_memcpy.c \
vect_itoa_cat.c \
vect_utoa_cat.c \
rev_char_arr.c \
vect_utohex_cat.c \
vect_ultohex_cat.c \
putvectbuff_ret_int.c


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
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[32;1m$@\033[32;0m\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "\033[32;1m[Create $(OBJ_DIR)]\033[32;0m\n"

$(NAME): $(OBJ_DIR) $(OBJS)
	@printf "\033[32;1m[Compiled /w CFLAGS=$(CFLAGS)]\033[32;0m\n"
	@ar -rcs $(NAME) $(OBJS)
	@printf "\033[32;1m[== Linked OK ==]\033[32;0m\n"

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
.PHONY: c, cf, r, git, fgit, m, mor, mft, exe, h

h:
	@echo "\033[1J"

exe:
	@./a.out

m: all
	$(CC) $(CFLAGS) $(INCLUDES) $(NAME) main.c

mor:
	$(CC) main.c  -D OR_
mft:
	$(CC) $(CFLAGS) $(INCLUDES) main.c $(NAME)  -D FT_

c: clean

fc: fclean

r: re

git:
	@git pull
	@git status --short
	@while true; do read -p "Continue [y/N]" resp; if [[ $$resp =~ ^[Yy]$$ ]]; then exit 0; else exit 1; fi; done
	@-git add .
	@git commit -am "Makefile push `date +'%Y-%m-%d %H:%M:%S'`"
	@-git push
