# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 04:37:44 by wseegers          #+#    #+#              #
#    Updated: 2018/05/28 05:53:46 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I ./include -I ../include

SRC := $(wildcard f_str*.c)

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

re : clean all
