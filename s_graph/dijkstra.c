/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 05:02:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 11:08:40 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_graph.h"
#include "s_vertex.h"
#include "f_memory.h"

int path_cost_cmp(void *vert1, void *vert2)
{
	if (((t_vert*)vert1)->path_cost < ((t_vert*)vert2)->path_cost)
		return (1);
	if (((t_vert*)vert1)->path_cost > ((t_vert*)vert2)->path_cost)
		return (-1);
	return (0);
}

void	s_path_visit(t_list *p_list)
{
	t_vert	*current;
	t_vert	*nbour;
	long	cost;
	size_t	visits;

	current = (t_vert*)s_list_pop(p_list, 0);
	current->visited = true;
	visits = -1;
	while (++visits < current->edges->size)
	{
		if (!(nbour = s_vert_get(current->edges, visits))->visited)
			s_list_append(p_list, nbour);
		if (nbour->path_cost > (cost = s_vert_cost(current, nbour)))
		{
			nbour->path_cost = cost;
			nbour->parent = current;
		}
	}
	s_list_mergesort(p_list, path_cost_cmp);
}


t_vert	*dijkstra(t_vert *start, t_vert *target)
{
	t_list	*p_list;

	p_list = s_list_create(NULL);
	s_list_append(p_list, start);
	start->path_cost = 0;
	while (!target->visited && p_list->size)
		s_path_visit(p_list);
	return (target);
}
