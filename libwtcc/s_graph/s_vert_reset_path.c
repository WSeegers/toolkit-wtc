/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_reset_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:13:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/13 12:20:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include "s_vertex.h"

void	s_vert_reset_path(t_vert *vert)
{
	vert->path_cost = INT_MAX;
	vert->visited = false;
	vert->parent = NULL;
}
