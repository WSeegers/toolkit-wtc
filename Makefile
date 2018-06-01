# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by wseegers          #+#    #+#              #
#    Updated: 2018/06/02 00:59:07 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = toolkit-wtc.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I include

F_IO_SRC = f_feedf.c f_initf.c f_openf.c f_readf.c f_writef.c f_stdio.c\
		   f_next_line.c
F_IO = $(addprefix f_io/, $(F_IO_SRC))

F_MATH_SRC = f_abs.c  f_max.c  f_min.c
F_MATH = $(addprefix f_math/, $(F_MATH_SRC))

F_MEMORY_SRC = f_membzero.c f_memchr.c f_memcpy.c f_memmove.c f_rawmemchr.c\
			   f_memalloc.c f_memccpy.c f_memcmp.c f_memdel.c f_memset.c
F_MEMORY = $(addprefix f_memory/, $(F_MEMORY_SRC))

F_PRINT_SRC = f_print_char.c f_print_nbr.c  f_print_str.c
F_PRINT = $(addprefix f_print/, $(F_PRINT_SRC))

F_STRING_SRC = f_strcmp.c f_strdel.c f_strdup.c f_strlcat.c f_strlen.c\
			   f_strnew.c f_strnlen.c f_strccpy.c f_strresize.c f_strncpy.c\
			   f_strchr.c f_islower.c f_toupper.c f_isspace.c f_isblank.c\
			   f_atoi.c f_strtol.c
F_STRING = $(addprefix f_string/, $(F_STRING_SRC))

S_GRID_SRC = s_grid_create.c s_grid_get.c s_grid_init.c s_grid_print.c\
			  s_grid_search.c
S_GRID = $(addprefix s_grid/, $(S_GRID_SRC))

S_LIST_SRC = s_list_append.c s_list_create.c s_list_node_create.c\
				s_list_clear.c s_list_init.c s_list_pop.c
S_LIST = $(addprefix s_list/, $(S_LIST_SRC))

OBJ_LIST = $(patsubst %.c, %.o, $(F_IO) $(F_MATH) $(F_MEMORY) $(F_PRINT)\
				$(F_STRING) $(F_GRID) $(FLIST))
BIN_PATH = bin
BIN = $(addprefix $(BIN_PATH)/, $(OBJ_LIST))

all : $(NAME)

$(NAME) : $(BIN)
	ar rc $@ $?
	ranlib $@

$(BIN_PATH)/%.o :  %.c
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(addprefix $(BIN_PATH)/,$(dir $<))
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

clean :
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
