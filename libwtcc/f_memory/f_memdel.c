/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:57:15 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/27 17:20:48 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	f_memdel(void **ap)
{
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = NULL;
}