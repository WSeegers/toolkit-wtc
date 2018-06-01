/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_stdio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:08:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/01 01:14:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_file.h"
#include "f_memory.h"

t_file	*f_stdio(int std_fd)
{
	static t_file	*stdi;
	static t_file	*stdo;
	static t_file	*stde;

	if (!stdi)
	{
		stdi = (t_file*)f_memalloc(sizeof(*stdi));
		*stdi = (t_file)STDIN_;
	}
	if (!stdo)
	{
		stdo = (t_file*)f_memalloc(sizeof(*stdi));
		*stdo = (t_file)STDOUT_;
	}
	if (!stde)
	{
		stde = (t_file*)f_memalloc(sizeof(*stdi));
		*stde = (t_file)STDERR_;
	}
	if (std_fd == 0)
		return (stdi);
	if (std_fd == 1)
		return (stdo);
	if (std_fd == 2)
		return (stde);
	return (NULL);
}
