/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:48:32 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/27 18:11:32 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LIST_H
# define S_LIST_H

# include "s_list_node.h"

typedef struct		s_list
{
	t_list_node	head;
	t_list_node tail;
	size_t		size;
	void		(*f_del_data)(void*);
}					t_list;


void	s_list_init(t_list **list, (*del_data)(void*));

#endif
