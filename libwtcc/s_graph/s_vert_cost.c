/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 07:04:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 10:36:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "s_vertex.h"

long	s_vert_cost(t_vert *from, t_vert *to)
{
	int	index;

	index = s_list_find(from->edges, to);
	if (index >= 0)
		return (*(long*)s_list_get(from->edge_cost, index));
	else
		return (LONG_MAX);
}
