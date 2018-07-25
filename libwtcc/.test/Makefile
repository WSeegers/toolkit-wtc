# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 03:41:36 by wseegers          #+#    #+#              #
#    Updated: 2018/06/06 20:29:49 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_test
MAIN = test_main.c
CC = clang
CFLAGS = -Werror -Wall -Wextra -I lib-utest/include -I ../include
LIB = -L lib-utest/ -lutest ../toolkit-wtc.a

F_IO_SRC = unit_f_initf.c  unit_f_openf.c  unit_f_readf.c  unit_f_writef.c\
		    unit_f_next_line.c
F_IO = $(addprefix f_io/, $(F_IO_SRC))

S_LIST_SRC = unit_s_list_insert.c unit_s_list_rot.c
S_LIST = $(addprefix s_list/, $(S_LIST_SRC))

S_DSTR_SRC = unit_new_dstr.c unit_cat_str.c unit_find_dstr.c unit_cut_dstr.c
S_DSTR = $(addprefix s_dstr/, $(S_DSTR_SRC))

OBJ_LIST = $(patsubst %.c, %.o, $(F_IO) $(F_MATH) $(F_MEMORY) $(F_PRINT)\
				$(F_STRING) $(S_GRID) $(S_LIST) $(S_DSTR))
BIN_PATH = bin
BIN = $(addprefix $(BIN_PATH)/, $(OBJ_LIST))
DEP := $(BIN:%.o=%.d)

all : make_all $(NAME)

make_all : 
	make -C	lib-utest 
	make -C ../	

$(NAME) : $(MAIN) $(BIN) 
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(BIN_PATH)/%.o :  %.c
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(addprefix $(BIN_PATH)/,$(dir $<))
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

clean : 
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)
	make fclean -C lib-utest 
	make fclean -C ../
	make fclean -C f_io

re : fclean all 
