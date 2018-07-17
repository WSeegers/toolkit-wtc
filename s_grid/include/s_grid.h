/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:37:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/17 23:48:32 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_GRID_H
# define S_GRID_H

# include <stdbool.h>

typedef struct		s_grid
{
	int		*data;
	int		width;
	int		height;
}					t_grid;

typedef struct		s_grid_point
{
	int		col;
	int		row;
	int		value;
}					t_grid_point;

# define GRID_GET(grid, x, y)	(grid.data[(y * grid.width) + x])

t_grid				*grid_create(void);
void				grid_init(t_grid *grid, int width, int height);
int					grid_get(t_grid *grid, int row, int col);
void				grid_print_fd(int fd, t_grid *grid);
void				grid_print(t_grid *grid);
void				grid_set(t_grid *grid, int val, int row, int col);

#endif
