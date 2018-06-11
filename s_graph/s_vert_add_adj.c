/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_add_adj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:44:11 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/11 08:52:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/s_vertex.h"
#include "s_list.h"

void	s_vert_add_adj(t_vert *vert, t_vert *neighbour, long cost)
{
	s_list_append(vert->adj_list, neighbour);
	s_list_append(vert->adj_list, (void*)cost);
}
