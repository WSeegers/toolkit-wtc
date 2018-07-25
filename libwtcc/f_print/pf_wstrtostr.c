/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:38:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 13:32:57 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/f_printf.h"
#include "f_memory.h"
#include <stdio.h>

int		pf_wstrtostr(char *buf, int *wstr, size_t n)
{
	char	bufc[5];
	size_t	i;
	size_t	clen;

	i = 0;
	while (*wstr)
	{
		clen = pf_wctostr(bufc, *wstr++);
		if (i + clen < n)
		{
			f_memcpy(buf + i, bufc, clen);
			i += clen;
		}
		else
			break ;
	}
	buf[i] = '\0';
	return (i);
}
