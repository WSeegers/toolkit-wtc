/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:36:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 14:28:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "include/f_printf.h"
#include "f_memory.h"

static unsigned int	pow10(exp)
{
	unsigned int ret;

	ret = 1;
	while (exp--)
		ret *= 10;
	return (ret);
}

int					pf_ftostr(long double nbr, char *str, unsigned int precision)
{
	unsigned long long	wnbr;
	long double			fraction;
	unsigned int		width;

	if (nbr > LLONG_MAX)
	{
		*str = '\0';
		return (0);
	}
	wnbr = (long long)nbr;
	width = pf_nbrtostr(wnbr, str, 10, 0);
	fraction = nbr - (long double)wnbr;
	if (precision)
	{
		str[width++] = '.';
		fraction = fraction * pow10(precision);
		width += pf_nbrtostr((long long)fraction, str + width, 10, 0);
	}
	str[width] = '\0';
	return (width);
}
