/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:57:03 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/09 22:34:10 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_printf_tag.h"
#include "f_memory.h"
#include "f_string.h"
#include "f_math.h"

int static pf_pad_nbr(char *buf, t_tag *tag, size_t n)
{
	size_t	buflen;
	
	tag->min_width = f_max(tag->min_width, tag->precision);
	if (n <= (buflen = f_strlen(buf)) || buflen > tag->min_width)
		return (buflen);
	tag->min_width = f_min(tag->min_width, n - buflen);
	if (buflen < tag->precision)
	{
		f_memmove(buf + tag->precision - buflen, buf, buflen);
		if (tag->zeropad)
			f_memset(buf, '0', tag->precision - buflen);
		else
			f_memset(buf, ' ', tag->precision - buflen);	
		buflen = tag->precision;
	}
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

int	static pf_pad_str(char *buf, t_tag *tag, size_t n)
{
	size_t	buflen;
	
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

int		pf_padding(char *buf, t_tag *tag, size_t n)
{
	if (f_strchr(STR_SPEC, tag->spec))
		return (pf_pad_str(buf, tag, n));
	else if (f_strchr(INT_SPEC, tag->spec) || f_strchr(FLT_SPEC, tag->spec))
		return (pf_pad_nbr(buf, tag, n));
	else
		return (f_strlen(buf));
}
