/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s_grid_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:47:49 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/29 14:49:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "s_grid.h"
#include "f_print.h"
#include "f_memory.h"

# define WIDTH 10
# define HEIGHT 40

int	main(void)
{
	t_grid	*grid;
	int		i;

	grid = s_grid_create(HEIGHT, WIDTH);
	i = -0;
	while (++i < HEIGHT * WIDTH)
		grid->plane[i] = i;
	s_grid_print(grid);	
	f_memdel((void**)&grid->plane);
	f_memdel((void**)&grid);
	return (1);
}
