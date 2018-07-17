/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:44:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/17 23:38:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"
#include "f_memory.h"

void	grid_init(t_grid *grid, int width, int height)
{
	grid->height = height;
	grid->width = width;
	if (height * width > 0)
		grid->data = (int*)f_memalloc(height * width * sizeof(*grid->data));
}
