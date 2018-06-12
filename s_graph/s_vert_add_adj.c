/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_add_adj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:44:11 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/12 10:05:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_vertex.h"
#include "include/s_graph.h"
#include "s_list.h"

int		s_vert_add_adj(t_vert *vert, t_vert *neighbour, long cost)
{
	if (s_vert_has_edge(vert, neighbour))
		return (0);
	s_list_append(vert->adj_list, neighbour);
	s_list_append(vert->cost, (void*)cost);
	return (1);
}
