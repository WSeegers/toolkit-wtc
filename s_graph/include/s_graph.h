/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_graph.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:22:48 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/12 10:09:36 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_GRAPH_H
# define S_GRAPH_H

# include "s_list.h"
# include "s_vertex.h"

typedef struct	s_graph
{
	t_list		*vert_list;
}				t_graph;

t_graph			*s_graph_create(void);
void			s_graph_init(t_graph *graph);
void			s_graph_add_vert(t_graph *graph, t_vert *vert);
t_vert			*s_vert_by_name(t_graph *graph, char *name);

#endif
