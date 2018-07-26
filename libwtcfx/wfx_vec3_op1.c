/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wfx_vec3_op1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 19:23:05 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/26 19:46:18 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwtcfx.h"

void	vec3_add(t_vec3 *v1, t_vec3 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

void	vec3_sub(t_vec3 *v1, t_vec3 v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
}

void	vec3_scale(t_vec3 *v1, double scalar)
{
	v1->x *= scalar;
	v1->y *= scalar;
	v1->z *= scalar;
}

void	vec3_norm(t_vec3 *v)
{
	vec3_scale(v, LEN_VEC3((*v)));
}