/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 22:00:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/07 20:47:23 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "f_string.h"
#include "include/s_printf_tag.h"
#include "include/f_printf.h"

int		pf_handle_str(char *buf, t_tag *tag, va_list ap, size_t n)
{
	char	*str;
	int 	*wstr;

	s_tag_get_width(tag, ap);
	s_tag_get_prec(tag, ap);
	if (tag->spec == 'S' || (tag->spec == 's' && tag->mem_size >= sizeof(int)))
	{
		if (!(wstr = va_arg(ap, int*)))
			f_strncpy(buf, "(null)", n);
		else
			pf_wstrtostr(buf, wstr, n);
	}
	else if (tag->spec == 's')
	{
		if (!(str = va_arg(ap, char*)))
			str = "(null)";
		f_strncpy(buf, str, n);
	}
	return (pf_padding(buf, tag, n));
}
