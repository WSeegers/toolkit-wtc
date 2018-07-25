/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:35:05 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 11:58:12 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_string.h"

void	cat_str(t_dstr *dstr, char *str)
{
	capchk_dstr(dstr, f_strlen(str));
	f_strcpy(dstr->str + dstr->len, str);
	dstr->len = f_strlen(dstr->str);
}
