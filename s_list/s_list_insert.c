/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:02:13 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 19:39:28 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void	s_list_insert(t_list *list, void *data, int i)
{
	t_list_node	*node;
	t_list_node	*new;

	if (!list->size || i == -1)
	{
		s_list_append(list, data);
		return ;
	}
	if (!(node = s_list_getnode(list, i)))
		return ;
	new = s_list_node_create(node->prev, node, data);
	if (node->prev)
		node->prev->next = new;
	else
		list->head = new;
	node->prev = new;
}
