# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 03:41:36 by wseegers          #+#    #+#              #
#    Updated: 2018/05/31 16:55:48 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_test

CC = clang
CFLAGS = -Werror -Wall -Wextra -I lib-utest/include 
LIB = -L lib-utest/ -lutest ../toolkit-wtc.a

MAIN = test_main.c
BIN_PATH = bin
BIN = 
DEP := $(BIN:%.o=%.d)

all : make_all $(NAME)

make_all : 
	make -C	lib-utest 
	make -C ../
	make -C f_io

$(NAME) : $(MAIN) $(wildcard $(BIN_PATH)/*.o)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean : 
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)
	make fclean -C lib-utest 
	make fclean -C ../
	make fclean -C f_io
	

re : fclean all 
