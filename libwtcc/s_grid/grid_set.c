/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:17:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/18 01:03:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"

void	grid_set(t_grid *grid, int val, int x, int y)
{
	if (y >= grid->height || x >= grid->width)
		return ;
	grid->data[((y * grid->width) + x)] = val;
}
