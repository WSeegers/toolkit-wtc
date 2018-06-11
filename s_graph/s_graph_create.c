/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_graph_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:29:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/11 08:50:07 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"
#include "s_list.h"
#include "include/s_graph.h"

static void del_vert(void *vert)
{
	f_memdel(&vert);
}

void	s_graph_init(t_graph *graph)
{
	graph->vert_list = s_list_create(del_vert);
}

t_graph	*s_graph_create(void)
{
	t_graph *graph;

	graph = (t_graph*)f_memalloc(sizeof(*graph));
	s_graph_init(graph);

	return (graph);
}
