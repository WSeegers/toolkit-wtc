/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vdprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:23:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 13:29:38 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "include/s_printf_tag.h"
#include "include/f_printf.h"
#include "f_print.h"
#include "f_string.h"
#include "f_memory.h"
#include "s_dstr.h"

/*
** These are cases that still need to be implimented
**
** else if (f_strchr(FLT_SPEC, tag->spec))
** 	pf_handle_float();
** else if (f_strchr(OTH_SPEC, tag->spec))
** 	pf_handle_other();
*/

static int		handle_tag(int fd, const char **format, va_list ap)
{
	t_tag	*tag;
	char	buf[PF_BUFFSIZE];

	tag = parse_tag(*format);
	if (tag->spec)
	{
		*format = tag->format;
		if (f_strchr(STR_SPEC, tag->spec))
			pf_handle_str(buf, tag, ap, sizeof(buf) - 1);
		else if (f_strchr(INT_SPEC, tag->spec))
			pf_handle_int(buf, tag, ap, sizeof(buf) - 1);
	}
	f_memdel((void**)&tag);
	return (f_print_str_fd(fd, buf));
}

static size_t	write_till_tag(int fd, const char *format)
{
	char *tag;

	if ((tag = get_tag(format)) && tag > format)
		return (write(fd, format, f_strchr(format, '%') - format));
	if (tag == format)
		return (0);
	return (f_print_str_fd(fd, format));
}

int				f_vdprintf(int fd, const char *format, va_list ap)
{
	int		ret;

	ret = write_till_tag(fd, format);
	while ((format = get_tag(format)))
	{
		ret += handle_tag(fd, &format, ap);
		ret += write_till_tag(fd, format);
	}
	return (ret);
}
