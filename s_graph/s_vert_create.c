/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:31:30 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/11 08:53:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	vert->adj_list = s_list_create(del_vert);
	vert->cost = s_list_create(NULL);
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
