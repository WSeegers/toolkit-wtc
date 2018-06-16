/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_func_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 04:52:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/16 10:12:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "s_list.h"

void	*s_list_func_find(t_list *list, bool (*chk)(void*, void*),
															void *chk_data)
{
	t_list_node	*cur;

	cur = list->head;
	while (cur)
	{
		if (chk(cur->data, chk_data))
			return (cur->data);
		cur = cur->next;
	}
	return (NULL);
}
