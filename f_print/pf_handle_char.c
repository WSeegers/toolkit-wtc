/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 04:31:12 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/28 05:22:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/f_printf.h"

void	pf_handle_char(t_tag *tag, va_list ap, t_buffer *buf)
{
	char	wchar[4];

	f_bzero(wchar, 4);
	if (tag->spec == 'C' || (tag->spec == 'c' && tag->mem_size >= sizeof(int)))
	{
		pf_wctostr(wchar, va_arg(ap, int));
		buffer_char(buf, wchar[0]);
		if (!wchar[1])
			return ;
		buffer_char(buf, wchar[1]);
		if (!wchar[2])
			return ;
		buffer_char(buf, wchar[2]);
		if (!wchar[3])
			return ;
		buffer_char(buf, wchar[3]);
	}
	else
		buffer_char(buf, (char)va_arg(ap, int));
}
