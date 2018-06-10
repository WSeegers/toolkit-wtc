/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 20:35:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 11:23:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include "f_string.h"
#include "f_memory.h"
#include "include/s_printf_tag.h"
#include "include/f_printf.h"

static void					hextoupper(char *c)
{
	*c = f_toupper(*c);
}

static unsigned long long 	get_size_mask(size_t n, long long nbr, bool has_sign)
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

static void					add_prefix(char *buf, t_tag *tag)
{
	if ((f_strchr("xX", tag->spec) && tag->prefix) || tag->spec == 'p')
	{
		f_memmove(buf + 2, buf, f_strlen(buf) + 1);
		f_memcpy(buf, "0x", 2);
	}
	else if (f_toupper(tag->spec) == 'O' && tag->prefix)
	{
		f_memmove(buf + 1, buf, f_strlen(buf) + 1);
		*buf = '0';
	}
	else if (f_strchr("dDi", tag->spec) 
								&& *buf != '-' && (tag->space || tag->force_sign))
	{
		f_memmove(buf + 1, buf, f_strlen(buf) + 1);
		if (tag->force_sign)
			*buf = '+';
		else
			*buf = ' ';
	}
}

int							pf_handle_int(char *buf, t_tag *tag, 
														va_list ap, size_t n)
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
	{
		nbr = get_size_mask(tag->mem_size, va_arg(ap, long long), false);
		pf_unbrtostr(nbr, buf, base, tag->precision);
	}
	else
	{
		nbr = get_size_mask(tag->mem_size, va_arg(ap, long long), true);
		pf_nbrtostr(nbr, buf, base, tag->precision);
	}
	if (tag->spec == 'X')
		f_striter(buf, hextoupper);
	add_prefix(buf, tag);
	return (pf_padding(buf, tag, n));
}
