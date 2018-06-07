/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:37:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/07 03:02:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			tag->expanded = true;
		else if ((is_flag = (*format == '0')))
			tag->pad = true;
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
		tag->min_len = f_atoi(format);
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
			tag->mem_size = SIZE_CHAR;
		else
			tag->mem_size = SIZE_SHORT;
	}
	else if (*format == 'l' && format++)
	{
		if (*format == 'l' && format++)
			tag->mem_size = SIZE_LLONG;
		else
			tag->mem_size = SIZE_LONG;
	}
	else if (*format == 'j' && format++)
		tag->mem_size = SIZE_IMAX;
	else if (*format == 'z' && format++)
		tag->mem_size = SIZE_T;
	return (format);
}

static const char *get_spec(t_tag *tag, const char *format)
{
	int i;

	i = -1;
	while (SPECS[++i])
		if (*format == SPECS[i] && format++)
		{
			tag->spec = SPECS[i];
			break ;
		}
	return (format);
}

/*static void	print_tag(t_tag *tag)
{
	f_print_str("left_just: ");
	f_print_nbr(tag->left_just);
	f_print_str("\nforce_sign: ");
	f_print_nbr(tag->force_sign);
	f_print_str("\nspace: ");
	f_print_nbr(tag->space);
	f_print_str("\nexpanded: ");
	f_print_nbr(tag->expanded);
	f_print_str("\nleft_pad: ");
	f_print_nbr(tag->pad);
	f_print_str("\nmin_len: ");
	f_print_nbr(tag->min_len);
	f_print_str("\nva_width: ");
	f_print_nbr(tag->va_width);
	f_print_str("\nprecision: ");
	f_print_nbr(tag->precision);
	f_print_str("\nva_prec: ");
	f_print_nbr(tag->va_prec);
	f_print_str("\nmem_size: ");
	f_print_nbr(tag->mem_size);
	f_print_str("\nspec: ");
	write(1, &(tag->spec), 1);
	f_print_str("\n");
}*/

t_tag	*parse_tag(const char *format)
{
	t_tag *tag;

	tag = (t_tag*)f_memalloc(sizeof(*tag));
	init_tag(tag);
	format = get_flags(tag, format + 1);
	format = get_width_prec(tag, format);
	format = get_mem_size(tag, format);
	format = get_spec(tag, format);
	tag->format = format;
	//print_tag(tag);
	return (tag);
}
