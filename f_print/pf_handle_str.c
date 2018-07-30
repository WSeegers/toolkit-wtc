/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 22:00:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 12:02:32 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "f_string.h"
#include "include/s_printf_tag.h"
#include "include/f_printf.h"

static char	*handle_precision(t_tag *tag, char *str, bool is_null)
{
	char	*new;

	if (is_null)
	{
		new = f_strnew(6);
		f_memcpy(new, "(null)", 6);
		return (new);
	}
	if (tag->p_set)
	{
		new = f_strnew(tag->precision);
		f_memcpy(new, str, tag->precision);
		return (new);
	}
	return (f_strdup(str));
}

static char	*handle_width(t_tag *tag, char *str)
{
	int		new_len;
	int		len;
	char	*new;

	len = f_strlen(str);
	if ((new_len = tag->min_width) < len)
		return (str);
	new = f_strnew(new_len);
	f_memset(new, ' ', new_len);
	if (tag->left_just)
		f_memcpy(new, str, len);
	else
		f_strcpy(new + (new_len - len), str);
	f_strdel(&str);
	return (new);
}

char	*pf_handle_str(t_tag *tag, va_list ap)
{
	char	wchr[4];
	char	*str;
	int		*wstr;
	bool	is_null;

	if (tag->spec == 'S' || (tag->spec == 's' && tag->mem_size >= sizeof(int)))
	{
		if (!(wstr = va_arg(ap, int*)))
			is_null = true;
		else
			str = pf_wstrtostr(wstr, tag->p_set, tag->precision);
	}
	else if (tag->spec == 's')
	{
		if (!(str = va_arg(ap, char*)))
			is_null = true;
	}
	str = handle_precision(tag, str, is_null);
	str = handle_width(tag, str);
	return (f_strdup(str));
}
