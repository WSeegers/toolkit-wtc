/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:37:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/17 23:44:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"

int		grid_get(t_grid *grid, int x, int y)
{
	if (y >= grid->height || x >= grid->width)
		return (0xffffffff);
	return (grid->data[((y * grid->width) + x)]);
}
