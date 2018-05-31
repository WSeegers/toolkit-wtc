/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s_grid_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:49:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/29 14:06:52 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"
#include "f_print.h"
#include "f_memory.h"

int	test1(void)
{
	t_grid *grid;

	grid = s_grid_create(20, 20);
	if (sizeof(*grid) != sizeof(t_grid))
		return(0);
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
