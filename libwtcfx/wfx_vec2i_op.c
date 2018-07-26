/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wfx_vec2i_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:12:48 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/26 19:56:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwtcfx.h"

void		vec2i_add(t_vec2i *v1, t_vec2i v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
}

void		vec2i_sub(t_vec2i *v1, t_vec2i v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
}

void		vec2i_scale(t_vec2i *v1, int scalar)
{
	v1->x *= scalar;
	v1->y *= scalar;
}
