/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vdprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:23:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 22:17:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "include/f_printf.h"
#include "f_print.h"

#include <stdio.h>
/*
** These are cases that still need to be implimented
**
** else if (f_strchr(FLT_SPEC, tag->spec))
** 	pf_handle_float();
** else if (f_strchr(OTH_SPEC, tag->spec))
** 	pf_handle_other();
*/

size_t	pf_handle_chr(char *buf, int fd, t_tag *tag, va_list ap)
{
	char	c;
	size_t	i;
	size_t	width;

	c = va_arg(ap, int) & 0xff;
	width = f_max(tag->min_width, 1);
	i = 0;
	if (tag->left_just)
		i += write(fd, &c, 1); 
	while (--width > 0)
		 i += write(fd, " ", 1);	
	if (!tag->left_just)
		i += write(fd, &c, 1);
	buf[tag->min_width] = '\0';
	return (i);
}

size_t	pf_handle_wchr(char *buf, int fd, t_tag *tag, va_list ap)
{
	int		c;
	size_t	i;
	size_t	width;

	c = va_arg(ap, int);
	width = f_max(tag->min_width, 1);
	i = 0;
	if (tag->left_just)
		 i += f_putchar_fd(c, fd); 
	while (--width > 0)
		 i += write(fd, " ", 1);	
	if (!tag->left_just)
		 i += f_putchar_fd(c, fd); 
	buf[tag->min_width] = '\0';
	return (i);
}

static int		handle_tag(int fd, const char **format, va_list ap)
{
	t_tag	tag;
	char	buf[PF_BUFFSIZE];

	parse_tag(&tag, *format, ap);
	*format = tag.format;
	if (tag.spec)
	{
		if (f_strchr(STR_SPEC, tag.spec))
			pf_handle_str(buf, &tag, ap, sizeof(buf) - 1);
		else if (f_strchr(INT_SPEC, tag.spec))
			pf_handle_int(buf, &tag, ap, sizeof(buf) - 1);
		else if (tag.spec == '%')
			pf_padding(buf, &tag, sizeof(buf) - 1);
		else if (tag.spec == 'C' ||
							(tag.spec == 'c' && tag.mem_size >= sizeof(int)))
			return (pf_handle_wchr(buf, fd, &tag, ap));
		else if (tag.spec == 'c')
			return (pf_handle_chr(buf, fd, &tag, ap));
	}
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
