/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vertex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:25:36 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 12:18:22 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_VERTEX_H
# define S_VERTEX_H

# include <stdbool.h>
# include "s_list.h"

typedef struct	s_vertex
{
	char			*name;
	t_list			*edges;
	t_list			*edge_cost;

	long			path_cost;
	struct s_vertex	*parent;
	bool			visited;
}				t_vert;

t_vert			*s_vert_create(char *name);
void			s_vert_init(t_vert *vert);
int				s_vert_add_adj(t_vert *vert, t_vert *neighbour, long cost);
bool			s_vert_has_edge(t_vert *from, t_vert *to);
t_vert			*s_vert_get(t_list *vert_list, int index);
long			s_vert_cost(t_vert *from, t_vert *to);
bool			s_vert_set_cost(t_vert *from, t_vert *to, long val);
void			s_vert_reset_path(t_vert *vert);

#endif
