/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vdprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:23:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/07 04:37:25 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "include/s_printf_tag.h"
#include "f_print.h"
#include "f_string.h"
#include "f_memory.h"



int		handle_tag(int fd, const char **format, va_list ap)
{
	t_tag *tag;
	int i;
	
	(void)fd;
	(void)ap;
	tag = parse_tag(*format);
	if (tag->spec)
	{
		*format = tag->format;
	}
	f_memdel((void**)&tag);
	return (0);
}

int		f_vdprintf(int fd, const char *format, va_list ap)
{
	int		ret;

	(void)ap;
	ret = 0;
	ret = write_till_tag(fd, format);
	while ((format = get_tag(format)))
	{
		ret += handle_tag(fd, &format, ap);
		ret += write_till_tag(fd, format);
	}

	return (ret);
}
