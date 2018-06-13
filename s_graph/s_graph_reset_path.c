/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_graph_reset_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:20:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 12:24:14 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_graph.h"

void	s_graph_reset_path(t_graph *graph)
{
	size_t	i;

	i = -1;
	while (++i < graph->size)
		s_vert_reset_path(s_vert_get(graph, i));
}
