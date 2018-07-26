/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wfx_vec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 21:29:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/26 20:01:56 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwtcfx.h"

t_vec2		*vec2_create(void)
{
	return (f_memalloc(sizeof(t_vec2)));
}

void		vec2_init(t_vec2 *v, t_vec2 val)
{
	*v = val;
}

t_vec2		*vec2_copy(t_vec2 v)
{
	t_vec2	*ret;

	ret = vec2_create();
	vec2_init(ret, v);
	return (ret);
}
