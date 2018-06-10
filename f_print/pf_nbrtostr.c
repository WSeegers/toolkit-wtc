/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:39:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 13:37:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"

int	pf_nbrtostr(long long nbr, char *str, unsigned int base,
														unsigned int min_width)
{
	unsigned int		i;
	unsigned long long	unbr;
	int					neg;

	neg = (nbr < 0) ? 1 : 0;
	unbr = (neg) ? -nbr : nbr;
	i = -1;
	while (unbr)
	{
		str[++i] = "0123456789abcdef"[(unbr % base)];
		unbr /= base;
	}
	while (++i < min_width)
		str[i] = '0';
	(neg && i && nbr) ? str[i++] = '-' : 0;
	f_memrev(str, i);
	str[i] = '\0';
	return (i);
}

int	pf_unbrtostr(unsigned long long unbr, char *str, unsigned int base,
														unsigned int min_width)
{
	unsigned int		i;

	i = -1;
	while (unbr)
	{
		str[++i] = "0123456789abcdef"[(unbr % base)];
		unbr /= base;
	}
	while (++i < min_width)
		str[i] = '0';
	f_memrev(str, i);
	str[i] = '\0';
	return (i);
}
