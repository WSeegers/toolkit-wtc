/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:40:43 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:07:27 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_memory.h"
#include "f_string.h"

void	del_dstr(t_dstr **dstr)
{
	if ((*dstr)->str)
		f_strdel(&(*dstr)->str);
	f_memdel((void**)dstr);
	*dstr = NULL;
}
