# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/12/01 16:59:28 by mahadad          ###   ########.fr        #
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

INCLUDES	+= -I includes -I ../libft/includes -I ../vector-buffer/includes
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

SRC		= $(notdir $(SRCS))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

DEP_LIBFT = ../libft/obj_libft
DEP_VECT = ../vector-buffer/obj_vector_buffer

VPATH	= $(SRC_DIR) $(OBJ_DIR) $(shell find $(SRC_DIR) -type d)

# _.-=+=-._.-=+=-._[ Rules ]_.-=+=-._.-=+=-._ #
.PHONY: all, clean, fclean, re

all: $(NAME)
	@printf "\033[32;1m[== $(NAME) Created ! ==]\033[32;0m\n"
	@if [[ $D = "1" ]]; then printf "\033[31;1m[/!\\ DEBUG ENABLE /!\\]\033[32;0m\n"; fi

$(DEP_LIBFT):
	@make only_obj -C ../libft
	
$(DEP_VECT):
	@make only_obj -C ../vector-buffer

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[32;1m$@\033[32;0m\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "\033[32;1m[Create $(OBJ_DIR)]\033[32;0m\n"

$(NAME): $(DEP_LIBFT) $(DEP_VECT) $(OBJ_DIR) $(OBJS)
	@printf "\033[32;1m[Compiled /w CFLAGS=$(CFLAGS)]\033[32;0m\n"
	ar -rcs $(NAME) $(OBJS) $(shell find $(DEP_LIBFT) -type f -name "*.o") $(shell find $(DEP_VECT) -type f -name "*.o")
	@printf "\033[32;1m[== Linked OK ==]\033[32;0m\n"

clean:
	make clean -C ../vector-buffer
	@rm -rf $(OBJS)
	@printf "\033[31;1m[Remove *.o]\033[32;0m\n"
	@rm -rf $(OBJ_DIR)
	@printf "\033[31;1m[Remove $(OBJ_DIR)]\033[32;0m\n"

fclean: clean
	make fclean -C ../vector-buffer
	@rm -f $(NAME)
	@printf "\033[31;1m[Remove $(NAME)]\033[32;0m\n"

re: fclean all

# _.-=+=-._.-=+=-._[ Dev Tools #TODO REMOVE ]_.-=+=-._.-=+=-._ #
.PHONY: c, cf, r, git, fgit, m, mor, mft, exe, test

exe:
	@./a.out

test : $(NAME)
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
