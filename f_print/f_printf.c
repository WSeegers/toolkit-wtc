/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:52:53 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/04 17:14:03 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdargs.h>
#include "f_print.h"

int f_vprintf(const char *format, va_list ap)
{
	return (f_vfprintf(STDOUT, format, ap));
}

int		f_printf(const char *format, ...)
{
	va_list ap;
	
	va_start(ap, format);
	return (f_vprintf(fmt, ap));
}
