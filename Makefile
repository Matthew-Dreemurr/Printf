# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 16:49:27 by mahadad           #+#    #+#              #
#    Updated: 2021/12/01 17:05:25 by mahadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, re, clean, fclean

all:
	make -C printf/

re:
	make re -C printf/

clean:
	make clean -C printf/

fclean:
	make fclean -C printf/

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
	@git diff
	@-git add .
	@git commit -am "Makefile push `date +'%Y-%m-%d %H:%M:%S'`"
	@-git push
