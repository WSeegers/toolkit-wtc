/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncat_dstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:22:32 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:14:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"

void	ncat_dstr(t_dstr *dest, t_dstr *src, size_t n)
{
	ncat_str(dest, src->str, n);
}
