/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 07:10:56 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 07:49:03 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_memory.h"
#include "f_string.h"

t_dstr	*new_str(char *str)
{
	t_dstr *dstr;
	size_t len
		
	len = strlen(str);
	dstr = init_str(len);
	f_strcpy(dstr->str, str);
	dstr->len = len;
	return (dstr);
}



