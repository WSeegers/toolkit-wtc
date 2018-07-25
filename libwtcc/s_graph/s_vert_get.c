/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vert_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 06:08:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/12 06:12:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"
#include "include/s_vertex.h"

t_vert	*s_vert_get(t_list *vert_list, int index)
{
	return ((t_vert*)s_list_get(vert_list, index));
}
