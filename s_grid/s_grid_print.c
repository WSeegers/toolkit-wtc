/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:13:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 20:33:51 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_grid.h"
#include "f_print.h"
#include "f_math.h"

void	s_grid_print_fd(int fd, t_grid *grid)
{
	int row;
	int col;

	row = -1;
	while (++row < grid->height)
	{
		col = -1;
		f_print_str_fd(fd, "| ");
		while (++col < grid->width)
		{
			f_print_nbr_fd(fd, s_grid_get(grid, row, col));
			f_print_str_fd(fd, " | ");
		}
		f_print_str_fd(fd, "\n");
	}
}

void	s_grid_print(t_grid *grid)
{
	s_grid_print_fd(1, grid);
}
