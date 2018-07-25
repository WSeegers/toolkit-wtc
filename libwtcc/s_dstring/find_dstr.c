/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:01:26 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:09:40 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_memory.h"
#include "f_string.h"

t_index	find_dstr(t_dstr *dstr, char *needle)
{
	char	*end;
	size_t	len;

	if (!(len = f_strlen(needle)))
		return (0);
	else if (len == 1)
		end = f_strchr(dstr->str, *needle);
	else
		end = f_strstr(dstr->str, needle);
	if (end)
		return (end - dstr->str);
	else
		return (-1);
}
