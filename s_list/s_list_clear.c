/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:12:28 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/27 18:21:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"

void	s_list_clear(t_list *list)
{
	t_list_node	cur;
	t_list_node	del;

	cur = list->head;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		list->f_del_data(del->data);
		f_memdel((void**)&del);
	}
	s_list_init(list, list->destroy);
}
