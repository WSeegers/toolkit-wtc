/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_node.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:54:15 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 21:18:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LIST_NODE_H
# define S_LIST_NODE_H

typedef struct		s_list_node
{
	struct s_list_node	*next;
	struct s_list_node	*prev;
	void				*data;
}					t_list_node;

t_list_node			*s_list_node_create(t_list_node *prev, t_list_node *next,
											void *data);

#endif
