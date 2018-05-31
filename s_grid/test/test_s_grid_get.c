/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s_grid_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:07:50 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/29 14:47:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"
#include "f_print.h"
#include "f_memory.h"

# define WIDTH 10
# define HEIGHT 40
int	test1(void)
{
	t_grid	*grid;
	int		i;

	grid = s_grid_create(HEIGHT, WIDTH);
	if (sizeof(*grid) != sizeof(t_grid))
		return(0);
	i = -0;
	while (++i < HEIGHT * WIDTH)
		grid->plane[i] = i;
	if (s_grid_get(grid, 0, 0) != 0)
		return (0);
	if (s_grid_get(grid, 9, 9) != 99)
		return (0);
	if (s_grid_get(grid, 39, 9) != 399)
		return (0);
	f_memdel((void**)&grid->plane);
	f_memdel((void**)&grid);
	return (1);
}

int		main(void)
{
	int		(*test[])(void) = {
		&test1, 
		NULL};
	int i  = -1;

	f_print_str("s_list_create:");	
	while (test[++i])
		if (test[i]())
			f_print_str(" [PASS]");
		else
			f_print_str(" [FAIL]");
	f_print_str("\n");
	return (0);	
}
