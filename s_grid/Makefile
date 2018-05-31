# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 04:37:44 by wseegers          #+#    #+#              #
#    Updated: 2018/05/29 14:52:13 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I ./include -I ../include

SRC := $(wildcard s_grid*.c)

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

re : clean all
