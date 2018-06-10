/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:17:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 13:36:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_printf_tag.h"

void	init_tag(t_tag *tag)
{
	tag->spec = 0;
	tag->left_just = false;
	tag->force_sign = false;
	tag->space = false;
	tag->prefix = false;
	tag->zeropad = false;
	tag->min_width = 0;
	tag->va_width = false;
	tag->precision = 0;
	tag->va_prec = false;
	tag->mem_size = 0;
}
