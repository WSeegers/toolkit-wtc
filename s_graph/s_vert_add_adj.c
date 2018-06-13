/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_add_adj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:44:11 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 10:36:27 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_vertex.h"
#include "include/s_graph.h"
#include "f_memory.h"
#include "s_list.h"
#include "f_print.h"

int		s_vert_add_adj(t_vert *vert, t_vert *neighbour, long cost)
{
	long *costptr;

	if (s_vert_has_edge(vert, neighbour))
		return (0);
	s_list_append(vert->edges, neighbour);
	costptr = f_memalloc(sizeof(long));
	*costptr = cost;
	s_list_append(vert->edge_cost, costptr);
	return (1);
}
