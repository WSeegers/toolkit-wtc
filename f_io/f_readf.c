/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:01:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 16:42:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "s_file.h"
#include "f_math.h"
#include "f_memory.h"
#include "f_print.h"

ssize_t		f_readf(char *ptr, t_file *file, size_t n)
{
	size_t csize;
	size_t total;
	
	total = 0;
	if (!(file->mode == 'r' || file->mode == 'R' || file->mode == 'W'))
		return (-1);
	while (n)
	{
		if (file->fpos == -1 || file->fpos == file->lread)
			if (!f_feedf(file))
					return (total);
		if (file->lread == -1)
			return (-1);
		csize = f_min(n, file->lread - file->fpos);	
		f_memcpy(ptr, file->buf + file->fpos, csize);
		total += csize;
		ptr += csize;
		n -= csize;
		file->fpos += csize;
	}
	return (total);
}
