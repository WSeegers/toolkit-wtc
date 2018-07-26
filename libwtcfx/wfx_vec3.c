/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wfx_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 19:47:33 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/26 20:00:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwtcfx.h"

t_vec3		*vec3_create(void)
{
	return (f_memalloc(sizeof(t_vec3)));
}

void		vec3_init(t_vec3 *v, t_vec3 val)
{
	*v = val;
}

t_vec3		*vec3_copy(t_vec3 v)
{
	t_vec3	*ret;

	ret = vec3_create();
	vec3_init(ret, v);
	return (ret);
}
