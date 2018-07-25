/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recap_dstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:04:49 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:18:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_math.h"
#include "f_memory.h"
#include "f_string.h"

size_t	recap_dstr(t_dstr *dstr, size_t len)
{
	size_t	ncap;
	char	*nstr;

	ncap = ((len / DSTR_INIT_SIZE) + 1) * (DSTR_INIT_SIZE + 1);
	nstr = (char*)f_memalloc(ncap);
	f_strncpy(nstr, dstr->str, ncap);
	f_strdel(&dstr->str);
	dstr->str = nstr;
	dstr->cap = ncap;
	return (dstr->cap);
}
