/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:44:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 20:34:52 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"
#include "f_memory.h"

void	s_grid_init(t_grid *grid, int height, int width)
{
	grid->height = height;
	grid->width = width;
	if (height * width > 0)
		grid->plane = (int*)f_memalloc(height * width * sizeof(*grid->plane));
	else
		grid->plane = NULL;
}
