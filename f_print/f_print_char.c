/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:21:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/29 14:22:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t		f_print_char_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}

ssize_t		f_print_char(char c)
{
	return (write(1, &c, 1));
}
