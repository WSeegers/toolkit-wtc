/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:39:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/09 19:00:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_memory.h"
#include "f_string.h"
#include "include/s_printf_tag.h"

int	pf_nbrtostr(long long nbr, char *str, unsigned int base)
{
	unsigned int		i;
	unsigned long long	unbr;
	int					neg;

	if (!nbr)
	{
		f_strcpy(str, "0");
		return (1);
	}
	neg = (nbr < 0) ? 1 : 0;
	unbr = (neg) ? -nbr : nbr;
	i = -1;
	while (unbr)
	{
		str[++i] = "0123456789abcdef"[(unbr % base)];
		unbr /= base;
	}
	if (neg)
		str[++i] = '-';
	f_memrev(str, ++i);
	str[i] = '\0';
	return (i);
}

int	pf_unbrtostr(unsigned long long unbr, char *str, unsigned int base)
{
	unsigned int		i;

	if (!unbr)
	{
		f_strcpy(str, "0");
		return (1);
	}
	i = -1;
	while (unbr)
	{
		str[++i] = "0123456789abcdef"[(unbr % base)];
		unbr /= base;
	}
	f_memrev(str, ++i);
	str[i] = '\0';
	return (i);
}
