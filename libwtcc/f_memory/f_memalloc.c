/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:59:57 by WSeegers          #+#    #+#             */
/*   Updated: 2018/06/25 06:52:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "f_memory.h"
#include "s_list.h"
#include "f_cntl.h"

void	*f_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	f_bzero(ptr, size);
	return (ptr);
}
