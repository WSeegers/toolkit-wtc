/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_digits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 08:23:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/24 08:25:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"

int		f_isdigits(char *s)
{
	while (*s)
	{
		if (!f_isdigit(*s))
			return (0);
		++s;
	}
	return (1);
}
