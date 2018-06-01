/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:54:25 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/10 18:21:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	long int ret;

	ret = ft_strtol(nptr, NULL, 10);
	if (ret == FT_LONG_MAX)
		return (-1);
	if (ret == FT_LONG_MIN)
		return (0);
	return ((int)ret);
}
