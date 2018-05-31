# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 10:43:28 by wseegers          #+#    #+#              #
#    Updated: 2018/05/31 16:00:58 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I ../../include -I ../lib-utest/include

SRC := unit_f_initf.c unit_f_openf.c unit_f_readf.c unit_f_writef.c

BIN_PATH = ../bin
BIN := $(addprefix $(BIN_PATH)/, $(SRC:.c=.o))
DEP := $(BIN:.o=.d)

all: $(BIN)

$(BIN_PATH)/%.o :  %.c
	@mkdir -p $(BIN_PATH)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

-include $(DEP)

clean :
	rm -f $(BIN)

fclean : clean

re : all
