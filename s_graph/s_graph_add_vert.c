/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_graph_add_vert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:38:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/11 08:40:07 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_graph.h"

void			s_graph_add_vert(t_graph *graph, t_vert *vert)
{
	s_list_append(graph->vert_list, vert);
}
