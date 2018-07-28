/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:38:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/28 04:02:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/f_printf.h"
#include "f_memory.h"
#include "f_string.h"
#include <stdio.h>

char	*pf_wstrtostr(int *wstr)
{
	char	bufc[4];
	char	*buf;
	char	*temp;
	size_t	clen;
	int		len;

	len = 512;
	buf = f_strnew(len);
	while (*wstr)
	{
		clen += pf_wctostr(bufc, *wstr++);

		if (clen + 4 > len)
		{
			temp = buf;
			buf = f_strnew((len *= 2));
			f_strcpy(buf, temp);
			f_strdel(&temp);
		}
		f_strlcat(buf, bufc, len);
	}
	return (buf);
}
