/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:01:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 19:55:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LIST_H
# define S_LIST_H

# include <stddef.h>
# include "s_list_node.h"

typedef struct		s_list
{
	t_list_node			*head;
	t_list_node			*tail;
	size_t				size;
	void				(*f_del_data)(void*);
}					t_list;

void				s_list_init(t_list *list, void (*del_data)(void*));
t_list				*s_list_create(void (*del_data)(void*));
void				s_list_append(t_list *list, void *data);
void				s_list_insert(t_list *list, void *data, int i);
void				s_list_clear(t_list *list);
void				*s_list_pop(t_list *list, int index);
t_list_node			*s_list_getnode(t_list *list, int i);
void				s_list_rot(t_list *list, int n);

#endif
