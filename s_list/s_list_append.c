/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:24:25 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 20:42:25 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void	s_list_append(t_list *list, void *data)
{
	if (list->size++)
	{
		list->tail->next = s_list_node_create(list->tail, NULL, data);
		list->tail = list->tail->next;
	}
	else
	{
		list->head = s_list_node_create(NULL, NULL, data);
		list->tail = list->head;
	}
}
