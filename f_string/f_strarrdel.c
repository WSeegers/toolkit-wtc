/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strarrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 21:56:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/11 22:05:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"
#include "f_memory.h"

void	f_strarrdel(char ***array)
{
	if (!array || !*array)
		return ;
	while (**array)
		f_strdel(*array++);
	f_memdel((void**)array);
	*array = NULL;
}
