/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_dstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:46:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:12:56 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"

void	merge_dstr(t_dstr *dest, t_dstr *src)
{
	cat_dstr(dest, src);
	del_dstr(&src);
}
