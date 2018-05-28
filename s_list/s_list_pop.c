/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:04:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 10:21:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "f_print_h"

static pop_head(size_t i, t_list *list)
{
	t_node node;
	void *data;
	
	node = list->head;
	while (i--)
		node = node->next;
	data = node->data;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	memdel((void**)&node);
	return (data);
}

static pop_tail(size_t i, t_list *list)
{
	t_node node;
	void *data;
	
	node = list->tail;
	while (--i)
		node = node->prev;
	data = node->data;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	memdel((void**)&node);
	return (data);

}

void	*s_list_pop(int index, t_list *list)
{
	if (index > t_list->size || -index >= index->size)
	{
		f_print_err("Index out of bounds");
		return (NULL);
	}
	if (index < 0)
		return (pop_tail(-index, list));
	else
		return (pop_head(index, list);
}
