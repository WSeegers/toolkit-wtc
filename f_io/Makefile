# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 04:37:44 by wseegers          #+#    #+#              #
#    Updated: 2018/05/31 17:06:16 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I ../include

SRC := f_feedf.c f_initf.c f_openf.c f_readf.c f_writef.c f_stdio.c

BIN_PATH = ../bin
BIN := $(addprefix $(BIN_PATH)/, $(SRC:.c=.o))
DEP := $(BIN:.o=.d)

all: $(BIN)

$(BIN_PATH)/%.o :  %.c
	@mkdir -p $(BIN_PATH)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

-include $(DEP)

clean :
	rm -f $(BIN) $(DEP)

fclean : clean

re : fclean all

export F_IO := $(BIN)
