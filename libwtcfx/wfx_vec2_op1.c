/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wfx_vec2_op1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:12:48 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/26 19:58:22 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwtcfx.h"

void		vec2_add(t_vec2 *v1, t_vec2 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
}

void		vec2_sub(t_vec2 *v1, t_vec2 v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
}

void		vec2_scale(t_vec2 *v1, double scalar)
{
	v1->x *= scalar;
	v1->y *= scalar;
}

void		vec2_norm(t_vec2 *v)
{
	vec2_scale(v, 1 / LEN_VEC2((*v)));
}
