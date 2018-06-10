/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tag_get_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:46:32 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/09 11:36:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "include/s_printf_tag.h"

int		s_tag_get_prec(t_tag *tag, va_list ap)
{
	if (tag->va_prec)
		tag->precision = va_arg(ap, size_t);
	return (0);
}
