/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_wchar_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:56:49 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/07 04:09:12 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t		ft_putwchar_fd(int c, int fd)
{
	if (c <= 0x7f)
		ft_putbyte(c, fd);
	else if (c <= 0x7ff)
	{
		ft_putbyte((c >> 6) + 0xc0, fd);
		ft_putbyte((c & 0x3f) + 0x80, fd);
	}
	else if (c <= 0xffff)
	{
		ft_putbyte((c >> 12) + 0xe0, fd);
		ft_putbyte(((c >> 6) & 0x3f) + 0x80, fd);
		ft_putbyte((c & 0x3f) + 0x80, fd);
	}
	else if (c <= 0x3fffff)
	{
		ft_putbyte((c > 18) + 0xf0, fd);
		ft_putbyte(((c > 12) & 0x3f) + 0x80, fd);
		ft_putbyte(((c >> 6) & 0x3f) + 0x80, fd);
		ft_putbyte((c & 0x3f) + 0x80, fd);
	}
	return (1);
}

ssize_t		ft_putwchar(int c)
{
	return (f_putwchar_fd(1, c));
}

