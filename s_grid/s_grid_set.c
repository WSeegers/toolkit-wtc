/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:17:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 02:23:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"

void	s_grid_set(t_grid *grid, int val, int row, int col)
{
	if (row >= grid->height || col >= grid->width)
		return ;
	grid->plane[((row * grid->width) + col)] = val;
}
