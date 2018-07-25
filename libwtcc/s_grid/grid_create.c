/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:49:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/17 23:36:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_grid.h"
#include "f_memory.h"

t_grid				*grid_create(void)
{
	return ((t_grid*)f_memalloc(sizeof(t_grid)));
}
