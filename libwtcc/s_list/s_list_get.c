/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:56:43 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/11 08:05:03 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"
#include "f_math.h"

static void	*get_head(t_list *list, size_t i)
{
	t_list_node	*node;
	void		*data;

	node = list->head;
	while (i--)
		node = node->next;
	data = node->data;
	return (data);
}

static void	*get_tail(t_list *list, size_t i)
{
	t_list_node	*node;
	void		*data;

	node = list->tail;
	while (--i)
		node = node->prev;
	data = node->data;
	return (data);
}

void		*s_list_get(t_list *list, int index)
{
	int		size_i;

	size_i = list->size;
	if (list->size == 0)
		return (NULL);
	if (index >= size_i || -index > size_i)
		return (NULL);
	if (index < 0)
		return (get_tail(list, f_abs(index)));
	else
		return (get_head(list, f_abs(index)));
}
