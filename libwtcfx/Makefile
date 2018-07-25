# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 06:27:18 by wseegers          #+#    #+#              #
#    Updated: 2018/07/25 08:13:59 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libwtcfx.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I include -I ../libwtcc/include

SRC =  wfx_blit.c wfx_circle.c wfx_clear_window.c wfx_get_mlx.c wfx_grid.c\
		wfx_image.c wfx_key_hooks.c wfx_line.c wfx_line_screen_clip.c\
		wfx_loop.c wfx_mouse_hooks.c wfx_rect.c\
		wfx_scale_color.c wfx_set_pixel.c wfx_state.c wfx_vec2.c wfx_vec2_op1.c\
		wfx_vec2_op2.c wfx_vec2i.c wfx_vec2i_op.c wfx_window.c wfx_xpm.c
OBJ = $(patsubst %.c, %.o, $(SRC))
BIN_PATH = bin
BIN = $(addprefix $(BIN_PATH)/, $(OBJ))

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
