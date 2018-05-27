/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:56:49 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/27 18:20:28 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"
#include "f_memory.h"

void	del_data_placeholder(void *data)
{
	(void)data;
}

void	s_list_init(t_list *list, (*del_data)(void*))
{
	list = f_memalloc(sizeof(**list));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->f_del_data = del_data;
	if (list->del_data == NULL)
		del_data = del_data_placeholder;
}
