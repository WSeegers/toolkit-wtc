/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tag_get_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:36:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/09 11:09:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "include/s_printf_tag.h"

int		s_tag_get_width(t_tag *tag, va_list ap)
{
	if (tag->va_width)
		tag->min_width = va_arg(ap, size_t);
	return (0);
}
