/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_dstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:06:44 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 14:19:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_string.h"
#include "f_memory.h"
#include "f_math.h"

/*
**	cut and return the cut part as a dstring.
**	size = 0 for the remainder of the string.
**	start < 0 to index from the back.
*/

t_dstr	*cut_dstr(t_dstr *dstr, t_index start, size_t size)
{
	t_dstr *seg;

	if (!size)
		size = dstr->len;
	if (start < 0)
	{
		start = dstr->len + start;
		size = dstr->len;
	}
	size = f_min(dstr->len - start, size);
	seg = init_dstr(size);
	ncat_str(seg, dstr->str + start, size);
	f_memmove(dstr->str + start, dstr->str + start + size,
										f_strlen(dstr->str + start + size));
	dstr->len -= size;
	f_bzero(dstr->str + dstr->len, dstr->cap - dstr->len);
	return (seg);
}
