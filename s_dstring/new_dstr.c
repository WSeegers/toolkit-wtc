/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 07:10:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:16:44 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_memory.h"
#include "f_string.h"

t_dstr	*new_dstr(char *str)
{
	t_dstr *dstr;
	size_t len;
		
	len = f_strlen(str);
	dstr = init_dstr(len);
	f_strcpy(dstr->str, str);
	dstr->len = len;
	return (dstr);
}



