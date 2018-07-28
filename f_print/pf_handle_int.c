/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 20:35:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/28 02:20:52 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // remove
#include <stdarg.h>
#include <stdint.h>
#include "f_string.h"
#include "f_memory.h"
#include "include/s_printf_tag.h"
#include "include/f_printf.h"

static void					hextoupper(char *c)
{
	while (*c)
	{
		*c = f_toupper(*c);
		c++;
	}
}

static unsigned long long	get_size_mask(size_t n, long long nbr,
																bool has_sign)
{
	if (has_sign)
	{
		if (n == 1)
			return ((char)nbr);
		if (n == 2)
			return ((short)nbr);
		if (!n || n == 4)
			return ((int)nbr);
		return ((long long)nbr);
	}
	if (n == 1)
		return ((unsigned char)nbr);
	if (n == 2)
		return ((unsigned short)nbr);
	if (!n || n == 4)
		return ((unsigned int)nbr);
	return ((unsigned long long)nbr);
}

static void					add_prefix(char *buf, t_tag *tag, bool width_check)
{
	int shift;

	shift = (tag->left_just) ? 0 : tag->diff;
	if ((f_strchr("xX", tag->spec) && tag->prefix) || tag->spec == 'p')
	{
		f_memmove(buf + 2 - (CLAMP(shift, 0, 2)), buf, f_strlen(buf) + 1);
		f_memcpy(buf, "0x", 2);
		(tag->left_just) && (buf[f_strlen(buf) - CLAMP(tag->diff, 0, 2)] = 0);
	}
	else if (f_toupper(tag->spec) == 'O' && tag->prefix && buf[0] != '0')
	{
		(tag->left_just) && (buf[f_strlen(buf) - CLAMP(tag->diff, 0, 1)] = 0);
		f_memmove(buf + 1 - (CLAMP(shift, 0, 1)), buf, f_strlen(buf) + 1);
		*buf = '0';
	}
	else if (f_strchr("dDi", tag->spec) && (tag->space || tag->force_sign
		|| tag->is_neg))
	{
		f_memmove(buf + 1 - (CLAMP(shift, 0, 1)), buf, f_strlen(buf) + 1);
		if (tag->is_neg)
			*buf = '-';
		else if (tag->force_sign)
			*buf = '+';
		else
			*buf = ' ';
		(tag->left_just) && (buf[f_strlen(buf) - CLAMP(tag->diff, 0, 1)] = 0);
	}
}

void	to_str(char *buf, t_tag *tag, va_list ap)
{
	long long			nbr;
	unsigned int		base;

	tag->mem_size = f_strchr("DOU", tag->spec) ? sizeof(long) : tag->mem_size;
	base = 10;
	if (f_toupper(tag->spec) == 'X' || tag->spec == 'p')
		base = 16;
	else if (f_toupper(tag->spec) == 'O')
		base = 8;
	if (f_strchr("uUxXoOp", tag->spec))
		nbr = get_size_mask(tag->mem_size, va_arg(ap, long long), false);
	else
	{
		nbr = get_size_mask(tag->mem_size, va_arg(ap, long long), true);
		if (nbr < 0)
		{
			nbr = -nbr;
			tag->is_neg = 1;
		}
	}
	tag->prefix = (nbr || f_toupper(tag->spec) == 'O') ? tag->prefix : false;
	pf_unbrtostr(nbr, buf, base);
}

char	*handle_width(t_tag *tag, char *buf)
{
	size_t	len;
	char	*ret;

	if (buf[0] && (!tag->zeropad || tag->p_set))
		add_prefix(buf, tag, false);
	len = f_strlen(buf);
	tag->diff = tag->min_width - len;
	ret = f_strnew((MAX(tag->min_width, len)) + 2);
	if (tag->zeropad && !tag->left_just && !tag->p_set)
		f_memset(ret, '0', (MAX(tag->min_width, len)));
	else
		f_memset(ret, ' ', (MAX(tag->min_width, len)));
	if (tag->left_just)
		f_memcpy(ret, buf, len);
	else
		f_memcpy(ret + (MAX(tag->min_width, len)) - len, buf, len);
	if (tag->zeropad && !tag->p_set)
		add_prefix(ret, tag, true);
	return (ret);
}

char	*handle_precision(t_tag *tag, char *buf)
{
	size_t	len;
	char	*ret;

	if ((len = f_strlen(buf)) > tag->precision)
		tag->precision = len;
	ret = f_strnew(tag->precision + 2);
	f_memset(ret, '0', tag->precision);
	f_memcpy(ret + tag->precision - len, buf, len);
	return (ret);
}

char	*pf_handle_int(t_tag *tag, va_list ap)
{
	char	nbr_buf[64];
	char	*buf1;
	char 	*buf2;

	to_str(nbr_buf, tag, ap);
	if (nbr_buf[0] == '0' && tag->p_set && !tag->precision &&
		!(f_toupper(tag->spec) == 'O' && tag->prefix))
		nbr_buf[0] = '\0';
	else if (tag->spec == 'X')
		hextoupper(nbr_buf);
	buf1 = handle_precision(tag, nbr_buf);
	buf2 = handle_width(tag, buf1);
	return (buf2);
}
