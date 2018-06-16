/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_graph.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:22:48 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/16 10:07:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_GRAPH_H
# define S_GRAPH_H

# include <stdbool.h>
# include "s_list.h"
# include "s_vertex.h"

typedef t_list	t_graph;

t_graph			*s_graph_create(void);
void			s_graph_add_vert(t_graph *graph, t_vert *vert);
t_vert			*s_vert_by_name(t_graph *graph, char *name);
t_graph			*dijkstra(t_vert *start, t_vert *target);
void			s_graph_reset_path(t_graph *graph);
bool			s_graph_equ(t_graph *g1, t_graph *g2);
void			s_graph_print_verts(t_graph *graph);

#endif
