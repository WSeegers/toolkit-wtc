/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:37:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 13:36:27 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "include/s_printf_tag.h"
#include "f_string.h"
#include "f_memory.h"
#include "f_print.h"

static const char	*get_flags(t_tag *tag, const char *format)
{
	bool is_flag;

	is_flag = true;
	while (is_flag)
	{
		is_flag = false;
		if ((is_flag = (*format == '-')))
			tag->left_just = true;
		else if ((is_flag = (*format == '+')))
			tag->force_sign = true;
		else if ((is_flag = (*format == ' ')))
			tag->space = true;
		else if ((is_flag = (*format == '#')))
			tag->prefix = true;
		else if ((is_flag = (*format == '0')))
			tag->zeropad = true;
		else if ((is_flag = (*format == '\'')))
			tag->sep = true;
		format += is_flag;
	}
	return (format);
}

static const char	*get_width_prec(t_tag *tag, const char *format)
{
	if (*format == '*' && format++)
		tag->va_width = true;
	else if (f_isdigit(*format))
	{
		tag->min_width = f_atoi(format);
		while (f_isdigit(*format))
			format++;
	}
	if (*format == '.' && format++)
	{
		if (*format == '*')
			tag->va_prec = true;
		else if (f_isdigit(*format))
		{
			tag->precision = f_atoi(format);
			while (f_isdigit(*format))
				format++;
		}
		else
			tag->precision = 0;
	}
	return (format);
}

static const char	*get_mem_size(t_tag *tag, const char *format)
{
	if (*format == 'h' && format++)
	{
		if (*format == 'h' && format++)
			tag->mem_size = sizeof(char);
		else
			tag->mem_size = sizeof(short);
	}
	else if (*format == 'l' && format++)
	{
		if (*format == 'l' && format++)
			tag->mem_size = sizeof(long long);
		else
			tag->mem_size = sizeof(long);
	}
	else if (*format == 'j' && format++)
		tag->mem_size = sizeof(intmax_t);
	else if (*format == 'z' && format++)
		tag->mem_size = sizeof(size_t);
	return (format);
}

static const char	*get_spec(t_tag *tag, const char *format)
{
	if (f_strchr(SPECS, *format))
		tag->spec = *format++;
	return (format);
}

t_tag				*parse_tag(const char *format)
{
	t_tag *tag;

	tag = (t_tag*)f_memalloc(sizeof(*tag));
	init_tag(tag);
	format = get_flags(tag, format + 1);
	format = get_width_prec(tag, format);
	format = get_mem_size(tag, format);
	format = get_spec(tag, format);
	tag->format = format;
	return (tag);
}
