/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:49:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/29 13:52:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"
#include "f_memory.h"

t_grid				*s_grid_create(int height, int width)
{
	t_grid	*grid;

	grid = (t_grid*)f_memalloc(sizeof(*grid));
	s_grid_init(grid, height, width);
	return (grid);
}
