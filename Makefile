# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 08:02:39 by wseegers          #+#    #+#              #
#    Updated: 2018/07/25 08:04:27 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	make -C libwtcc
	make -C libwtcfx

clean :
	make -C libwtcc clean
	make -C libwtcfx clean

fclean :
	make -C libwtcc fclean
	make -C libwtcfx fclean

re :
	make -C libwtcc re
	make -C libwtcfx re