/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:31:30 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 08:51:21 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "include/s_vertex.h"
#include "f_memory.h"
#include "f_string.h"

static void del_vert(void *vert)
{
	f_memdel(&vert);
}

void	s_vert_init(t_vert *vert)
{
	vert->name = NULL;
	vert->edges = s_list_create(del_vert);
	vert->edge_cost = s_list_create(NULL);
	vert->path_cost = INT_MAX;
	vert->parent = NULL;
	vert->visited = false;
}

t_vert	*s_vert_create(char *name)
{
	t_vert *vert;

	vert = (t_vert*)f_memalloc(sizeof(*vert));
	s_vert_init(vert);
	if (!name)
		vert->name = f_strdup("No_name");
	else
		vert->name = f_strdup(name);
	return (vert);
}
