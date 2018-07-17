/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:13:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/17 23:54:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_grid.h"
#include "f_print.h"
#include "f_math.h"

void	grid_print_fd(int fd, t_grid *grid)
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
			f_print_nbr_fd(fd, grid_get(grid, row, col));
			f_print_str_fd(fd, " | ");
		}
		f_print_str_fd(fd, "\n");
	}
}

void	grid_print(t_grid *grid)
{
	grid_print_fd(1, grid);
}
