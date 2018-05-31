/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:37:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 20:30:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"
#include "f_print.h"

int		s_grid_get(t_grid *grid, int row, int col)
{
	if (row >= grid->height || col >= grid->width)
		return (0xffffffff);
	return (grid->plane[((row * grid->width) + col)]);
}
