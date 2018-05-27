/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_node_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:31:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/27 18:36:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

t_list_node	*s_list_node_create(t_list_node *prev, t_list_node *next,
																 void* data)
{
	t_list_node *node;

	if (node = ft_memalloc(sizeof(*node)))
	{
		node->prev = prev;
		node->next = next;
		node->data = data;
	}
	return (node);
}
