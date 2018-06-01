/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:54:25 by WSeegers          #+#    #+#             */
/*   Updated: 2018/06/02 00:52:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_string.h"

int		f_atoi(const char *nptr)
{
	long int ret;

	ret = f_strtol(nptr, NULL, 10);
	if (ret == FT_LONG_MAX)
		return (-1);
	if (ret == FT_LONG_MIN)
		return (0);
	return ((int)ret);
}
