/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vdprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:23:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/27 19:04:43 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "include/f_printf.h"
#include "f_print.h"

#include <stdio.h> // Remove

static char	*handle_tag(const char **format, va_list ap)
{
	t_tag	tag;

	parse_tag(&tag, *format, ap);
	*format = tag.format;
	if (f_strchr(INT_SPEC, tag.spec))
		return (pf_handle_int(&tag, ap));
	return ("|tag|");
}

int			f_vdprintf(int fd, const char *format, va_list ap)
{
	int			ret;
	t_buffer	buf;

	buf.pos = -1;
	buf.total = 0;
	while (*format)
	{
		buffer_fmt(&buf, &format, fd);
		if (*format)
			buffer_arg(&buf, handle_tag(&format, ap), fd);
	}
	flush(fd, &buf);
	return (buf.total);
}
