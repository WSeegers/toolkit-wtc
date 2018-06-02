/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_grid.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:37:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 02:24:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_GRID_H
# define S_GRID_H

# include <stdbool.h>

typedef struct		s_grid
{
	int		*plane;
	int		height;
	int		width;
}					t_grid;

typedef struct		s_grid_point
{
	int		col;
	int		row;
	int		value;
}					t_grid_point;

t_grid				*s_grid_create(int height, int width);
void				s_grid_init(t_grid *grid, int height, int width);
int					s_grid_get(t_grid *grid, int row, int col);
void				s_grid_print_fd(int fd, t_grid *grid);
void				s_grid_print(t_grid *grid);
void				s_grid_set(t_grid *grid, int val, int row, int col);
void				s_grid_search(t_grid *grid, t_grid_point *point,
													bool (*f_filter)(int));

#endif
