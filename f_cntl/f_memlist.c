/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 08:30:51 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/24 08:39:57 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"
#include "s_list.h"

static void	freemem(void *ptr)
{
	f_memdel(&ptr);
}

t_list	*f_memlist(void)
{
	static t_list	*memlist;

	if (!memlist)
		memlist = s_list_create(freemem);
	return (memlist);
}
