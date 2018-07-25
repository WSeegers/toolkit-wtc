/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncat_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:19:21 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:15:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_string.h"

void	ncat_str(t_dstr *dstr, char *str, size_t n)
{
	capchk_dstr(dstr, f_strlen(str));
	f_strncpy(dstr->str + dstr->len, str, n);
	dstr->len = f_strlen(dstr->str);
}
