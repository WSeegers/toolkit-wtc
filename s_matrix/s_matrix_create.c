/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_matrix_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 06:14:17 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/26 07:48:54 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_matrix.h"
#include "f_memory.h"

t_matrix4	s_matrix4_create(void)
{
	return((t_matrix4)f_memalloc(sizeof(4 * 4 * sizeof(double))));
}

t_matrix3	s_matrix3_create(void)
{
	return((t_matrix3)f_memalloc(sizeof(3 * 3 * sizeof(double))));
}
