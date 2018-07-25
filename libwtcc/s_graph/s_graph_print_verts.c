/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_graph_print_verts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:42:09 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 15:14:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_print.h"
#include "s_graph.h"

void	s_graph_print_verts(t_graph *graph)
{
	size_t	i;

	i = -1;
	while (++i < graph->size)
		f_printf("[%lu]%s ", i, s_vert_get(graph, i)->name);
}
