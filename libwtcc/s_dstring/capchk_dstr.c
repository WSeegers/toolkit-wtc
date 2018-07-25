/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capchk_dstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:14:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 11:56:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"

bool	capchk_dstr(t_dstr *dstr, size_t len)
{
	if (dstr->len + len > dstr->cap)
	{
		recap_dstr(dstr, dstr->len + len);
		return (true);
	}
	return (false);
}
