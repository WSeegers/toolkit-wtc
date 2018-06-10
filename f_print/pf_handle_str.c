/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 22:00:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 13:38:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "f_string.h"
#include "include/s_printf_tag.h"
#include "include/f_printf.h"

int		pf_handle_str(char *buf, t_tag *tag, va_list ap, size_t n)
{
	s_tag_get_width(tag, ap);
	s_tag_get_prec(tag, ap);
	if (tag->spec == 'S' || (tag->spec == 's' && tag->mem_size >= sizeof(int)))
		pf_wstrtostr(buf, va_arg(ap, int*), n);
	else if (tag->spec == 'C' ||
							(tag->spec == 'c' && tag->mem_size >= sizeof(int)))
		pf_wctostr(buf, va_arg(ap, int));
	else if (tag->spec == 's')
		f_strncpy(buf, va_arg(ap, char*), n);
	else if (tag->spec == 'c')
	{
		buf[0] = va_arg(ap, int) & 0xff;
		buf[1] = '\0';
	}
	return (pf_padding(buf, tag, n));
}
