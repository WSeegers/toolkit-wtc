/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 10:16:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/27 10:20:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/f_printf.h"

void	flush(int fd, t_buffer *buf)
{
	buf->total += write(fd, buf->data, buf->pos + 1);
	buf->pos = -1;
}

void	buffer_fmt(t_buffer *buf, const char **format, int fd)
{
	char *fmt;

	fmt = (char*)*format;
	while (*fmt && *fmt != '%')
	{
		if (buf->pos == PF_BUFFSIZE)
			flush(fd, buf);
		buf->data[++buf->pos] = *fmt++;
	}
	*format = fmt;
}

void	buffer_arg(t_buffer *buf, char *s, int fd)
{
	while (*s)
	{
		if (buf->pos == PF_BUFFSIZE)
			flush(fd, buf);
		buf->data[++buf->pos] = *s++;
	}
}
