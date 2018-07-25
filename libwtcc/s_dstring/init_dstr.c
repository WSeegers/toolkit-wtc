/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 06:58:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:10:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_memory.h"

t_dstr	*init_dstr(size_t cap)
{
	t_dstr *dstr;

	dstr = f_memalloc(sizeof(*dstr));
	cap = ((cap / DSTR_INIT_SIZE) + 1) * (DSTR_INIT_SIZE + 1);
	dstr->str = (char*)f_memalloc(cap);
	dstr->cap = cap;
	dstr->len = 0;
	return (dstr);
}
