/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 06:58:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 07:10:29 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_memory.h"

t_dstr	*init_str(size_t capacity)
{
	t_dstr *dstr;

	dstr = f_memalloc(sizeof(*dstr));
	capacity = ((capacity + 1) / DSTR_INIT_SIZE) * (DSTR_INIT_SIZE + 1);
	dstr->str = (char*)f_memalloc(capacity);
	dstr->cap = capacity;
	dstr->len = 0;
}
