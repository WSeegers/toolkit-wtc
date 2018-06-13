/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_by_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 04:48:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 11:47:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "include/s_vertex.h"
#include "include/s_graph.h"
#include "s_list.h"
#include "f_string.h"

static bool	list_name_chk(void *vertex, void *name)
{
	if (!f_strcmp(((t_vert*)vertex)->name, (char*)name))
		return (true);
	return (false);
}

t_vert		*s_vert_by_name(t_graph *graph, char *name)
{
	return (s_list_func_find(graph, list_name_chk, name));
}
