# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by wseegers          #+#    #+#              #
#    Updated: 2018/06/07 03:19:20 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = toolkit-wtc.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I include

F_IO_SRC = f_feedf.c f_initf.c f_openf.c f_readf.c f_writef.c f_stdio.c\
		   f_next_line.c f_skip_line.c
F_IO = $(addprefix f_io/, $(F_IO_SRC))

F_MATH_SRC = f_abs.c  f_max.c  f_min.c
F_MATH = $(addprefix f_math/, $(F_MATH_SRC))

F_MEMORY_SRC = f_membzero.c f_memchr.c f_memcpy.c f_memmove.c f_rawmemchr.c\
			   f_memalloc.c f_memccpy.c f_memcmp.c f_memdel.c f_memset.c\
			   f_ptrdiff.c
F_MEMORY = $(addprefix f_memory/, $(F_MEMORY_SRC))

F_PRINT_SRC = f_print_char.c f_print_nbr.c  f_print_str.c f_vdprintf.c\
			  f_printf.c get_tag.c parse_tag.c write_till_tag.c init_tag.c
F_PRINT = $(addprefix f_print/, $(F_PRINT_SRC))

F_STRING_SRC = f_strcmp.c f_strdel.c f_strdup.c f_strlcat.c f_strlen.c\
			   f_strnew.c f_strnlen.c f_strccpy.c f_strresize.c f_strncpy.c\
			   f_strchr.c f_islower.c f_toupper.c f_isspace.c f_isblank.c\
			   f_atoi.c f_strtol.c f_isdigit.c f_strcpy.c f_strjoin.c\
			   f_strstr.c f_strncmp.c f_itoa_base.c
F_STRING = $(addprefix f_string/, $(F_STRING_SRC))

S_GRID_SRC = s_grid_create.c s_grid_get.c s_grid_init.c s_grid_print.c\
			 s_grid_search.c s_grid_set.c
S_GRID = $(addprefix s_grid/, $(S_GRID_SRC))

S_LIST_SRC = s_list_append.c s_list_create.c s_list_node_create.c\
			 s_list_clear.c s_list_init.c s_list_pop.c s_list_insert.c\
			 s_list_getnode.c s_list_rot.c
S_LIST = $(addprefix s_list/, $(S_LIST_SRC))

S_DSTR_SRC = capchk_dstr.c cat_dstr.c cat_str.c cut_dstr.c del_dstr.c\
			 find_dstr.c init_dstr.c isempty_dstr.c len_dstr.c merge_dstr.c\
			 ncat_dstr.c ncat_str.c new_dstr.c print_dstr.c recap_dstr.c
S_DSTR =  $(addprefix s_dstring/, $(S_DSTR_SRC))

OBJ_LIST = $(patsubst %.c, %.o, $(F_IO) $(F_MATH) $(F_MEMORY) $(F_PRINT)\
				$(F_STRING) $(S_GRID) $(S_LIST) $(S_DSTR))
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
