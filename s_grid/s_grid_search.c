/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:02:28 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/29 15:29:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_grid.h"

void	s_grid_search(t_grid *grid, t_grid_point *point, bool (*f_filter)(int))
{
	int	row;
	int	col;

	row = -1;
	while (row < grid->height)
	{
		col = -1;
		while (col < grid->width)
		{
			if (f_filter(s_grid_get(grid, row, col)))
			{
				point->row = row;
				point->col = col;
				point->value = s_grid_get(grid, row, col);
			}
		}
	}
}
