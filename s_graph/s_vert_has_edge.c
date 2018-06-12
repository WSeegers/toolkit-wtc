/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_has_edge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:14:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/12 10:03:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_vertex.h"
#include "s_list.h"

bool	s_vert_has_edge(t_vert *from, t_vert *to)
{
	if (s_list_find(from->adj_list, to) >= 0)
		return (true);
	return (false);
}
