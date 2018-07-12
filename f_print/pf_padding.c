/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:57:03 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/09 21:46:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "include/f_printf.h"
#include "include/s_printf_tag.h"
#include "f_memory.h"
#include "f_string.h"
#include "f_math.h"

static void pad_prec_int(char *buf, t_tag *tag)
{
	char temp[PF_BUFFSIZE];
	char *b_ptr;
	char *t_ptr;
	size_t buflen;
	int i;

	i = 0;
	if ((buf[0] == '0' && f_toupper(buf[1]) == 'X'))
		i = 2;
	else if (buf[0] == '-' || buf[0] == '+')
		i = 1;
	if (tag->zeropad && !tag->left_just)
		tag->precision = (tag->min_width < tag->precision) ? tag->precision :
			tag->min_width - i;
	if ((buflen = f_strlen(buf + i)) > tag->precision)
		return ;
	f_strcpy(temp, buf + i);
	f_memset(buf + i, '0', tag->precision);
	b_ptr = f_strchr(buf, 0) - 1;
	t_ptr = f_strchr(temp, 0) - 1;
	while (buflen--)
		*b_ptr-- = *t_ptr--;
}

int static	pf_pad_nbr(char *buf, t_tag *tag, size_t n)
{
	size_t i;

	(void)n;
	pad_prec_int(buf, tag);
	i = f_strlen(buf);
	if (i < tag->min_width && !tag->left_just)
	{
		f_memmove(buf + (tag->min_width - i), buf, f_strlen(buf));
		f_memset(buf, ' ', (tag->min_width - i));
	}
	else 
	{
		while (i < tag->min_width)
			buf[i++] = ' ';
		buf[i] = '\0';
	}
	return (0);
}

int	static	pf_pad_str(char *buf, t_tag *tag, size_t n)
{
	size_t	buflen;
	
	if (tag->p_set)
		buf[tag->precision] = '\0';
	if (n <= (buflen = f_strlen(buf)) || buflen > tag->min_width)
		return (buflen);
	tag->min_width = f_min(tag->min_width, n - buflen);
	if (tag->left_just)
			f_memset(buf + buflen, ' ', tag->min_width - buflen);
	else
	{
		f_memmove(buf + tag->min_width - buflen, buf, buflen);
		f_memset(buf, ' ', tag->min_width - buflen);
	}
	buf[tag->min_width] = '\0';
	return (tag->min_width);
}

int			pf_padding(char *buf, t_tag *tag, size_t n)
{
	if (f_strchr(STR_SPEC, tag->spec))
		return (pf_pad_str(buf, tag, n));
	else if (f_strchr(INT_SPEC, tag->spec) || f_strchr(FLT_SPEC, tag->spec)
			|| tag->spec == '%')
	{
		if (tag->spec == '%')
			f_strcpy(buf, "%");
		return (pf_pad_nbr(buf, tag, n));
	}
	else
		return (f_strlen(buf));
}
