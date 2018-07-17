/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:17:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/17 23:44:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"

void	s_grid_set(t_grid *grid, int val, int row, int col)
{
	if (row >= grid->height || col >= grid->width)
		return ;
	grid->data[((row * grid->width) + col)] = val;
}
