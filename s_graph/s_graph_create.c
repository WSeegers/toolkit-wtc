/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_graph_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:29:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 11:45:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"
#include "s_list.h"
#include "include/s_graph.h"

t_graph	*s_graph_create(void)
{
	t_graph *graph;

	graph = s_list_create(NULL);
	return (graph);
}
