/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 22:00:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/28 05:18:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "f_string.h"
#include "include/s_printf_tag.h"
#include "include/f_printf.h"

char	*pf_handle_str(t_tag *tag, va_list ap)
{
	char	wchr[4];
	char	*str;
	char 	*new;
	int		*wstr;

	if (tag->spec == 'S' || (tag->spec == 's' && tag->mem_size >= sizeof(int)))
	{
		if (!(wstr = va_arg(ap, int*)))
			return (f_strdup("(null)"));
		else
			str = pf_wstrtostr(wstr);
	}
	else if (tag->spec == 's')
	{
		if (!(str = va_arg(ap, char*)))
			return (f_strdup("(null)"));
	}
	if (tag->p_set)
	{
		new = f_strnew(tag->precision);
		f_memcpy(new, str, tag->precision);
		return (new);
	}
	return (f_strdup(str));
}
