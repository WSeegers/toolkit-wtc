/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vertex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:25:36 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/11 08:52:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_VERTEX_H
# define S_VERTEX_H

# include "s_list.h"

typedef struct	s_vertex
{
	char	*name;
	t_list	*adj_list;
	t_list	*cost;
}				t_vert;

t_vert			*s_vert_create(char *name);
void			s_vert_init(t_vert *vert);
void			s_vert_add_adj(t_vert *vert, t_vert *neighbour, long cost);

#endif
