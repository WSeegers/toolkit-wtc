/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isempty_dstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:44:11 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 14:18:38 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"

bool	isempty_dstr(t_dstr *dstr)
{
	return (dstr->len == 0);
}