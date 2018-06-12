/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:52:14 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/12 12:01:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"
#include "f_print.h"

t_list	*s_list_copy(t_list *orig)
{
	t_list	*copy;
	size_t	i;

	copy = s_list_create(orig->f_del_data);
	i = -1;
	while (++i < orig->size)
		s_list_append(copy, s_list_get(orig, i));
	return (copy);
}
