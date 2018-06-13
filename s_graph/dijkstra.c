/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 05:02:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 15:13:43 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_graph.h"
#include "s_vertex.h"
#include "f_memory.h"
#include "f_print.h"

int path_cost_cmp(void *vert1, void *vert2)
{
	if (((t_vert*)vert1)->path_cost < ((t_vert*)vert2)->path_cost)
		return (1);
	if (((t_vert*)vert1)->path_cost > ((t_vert*)vert2)->path_cost)
		return (-1);
	return (0);
}

void	s_path_visit(t_list *p_list, t_vert *target)
{
	t_vert	*current;
	t_vert	*nbour;
	long	edge_cost;
	size_t	visits;

	current = (t_vert*)s_list_pop(p_list, 0);
	current->visited = true;
	visits = -1;
	if (current == target)
		return ;
	while (++visits < current->edges->size)
	{
		if (!(nbour = s_vert_get(current->edges, visits))->visited)
			s_list_append(p_list, nbour);
		if (nbour->path_cost > 
				(edge_cost = s_vert_cost(current, nbour) + current->path_cost))
		{
			nbour->path_cost = edge_cost;
			nbour->parent = current;
		}
	}
	s_list_mergesort(p_list, path_cost_cmp);
}


t_graph		*dijkstra(t_vert *start, t_vert *target)
{
	t_list	*p_list;
	t_list	*s_path;

	p_list = s_list_create(NULL);
	s_path = s_list_create(NULL);
	s_list_append(p_list, start);
	start->path_cost = 0;
	while (!target->visited && p_list->size)
		s_path_visit(p_list, target);
	if (target->parent)
		while (target)
		{
			s_list_insert(s_path, target, 0);
			target = target->parent;
		}
	return (s_path);
}
