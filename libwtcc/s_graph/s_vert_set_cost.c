/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_set_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:36:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 11:49:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include "s_vertex.h"

bool	s_vert_set_cost(t_vert *from, t_vert *to, long val)
{
	int	index;

	index = s_list_find(from->edges, to);
	if (index >= 0)
	{
		*(long*)s_list_get(from->edge_cost, index) = val;
		return (1);
	}
	else
		return (0);
}
