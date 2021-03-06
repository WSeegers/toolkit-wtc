/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wfx_vec2_op2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:19:58 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/26 20:02:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwtcfx.h"

t_vec2	vec2_rotate(t_vec2 v, double rad)
{
	double s;
	double c;

	c = cos(rad);
	s = sin(rad);
	return (VEC2(v.x * c + v.y * -s, v.x * s + v.y * c));
}

double	vec2_angle(t_vec2 v)
{
	return (atan(v.y / v.x));
}
