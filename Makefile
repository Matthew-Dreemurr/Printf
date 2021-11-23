# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/11/23 14:14:15 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _.-=+=-._.-=+=-._[ Var ]_.-=+=-._.-=+=-._ #
CC			= gcc

D = 0
WRR = 1
SANI = 0

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
putstr_ret_int.c \
strlen_protect.c \
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
