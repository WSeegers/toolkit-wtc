/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:17:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 23:55:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_printf_tag.h"

void	init_tag(t_tag *tag)
{
	tag->spec = 0;

	tag->left_just = false;
	tag->force_sign = false;
	tag->space = false;
	tag->expanded = false;
	tag->left_pad = false;

	tag->min_len = 1;
	tag->va_width = false;

	tag->precision = 0;
	tag->va_prec = false;
	
	tag->mem_size = 0;
}
