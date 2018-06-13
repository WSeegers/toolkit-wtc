/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_graph_equ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:25:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 15:13:54 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_graph.h"

bool	s_graph_equ(t_graph *g1, t_graph *g2)
{
	size_t i;
	t_vert *v1;
	t_vert *v2;

	i = -1;
	if ((!g1 && g2) || (!g2 && g1))
		return (false);
	if (g1 == g2)
		return (true);
	while (++i < g1->size)
	{
		v1 = s_vert_get(g1, i);
		v2 = s_vert_get(g2, i);
		if (v2 != v1)
			return (false);
	}
	return (true);
}

