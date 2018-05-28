/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 04:31:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 09:26:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"
#include "f_memory.h"

t_list	*s_list_create(void (*del_data)(void*))
{
	t_list *list;

	list = 	(t_list*)f_memalloc(sizeof(*list));
	s_list_init(list, del_data);
	return (list);
}
