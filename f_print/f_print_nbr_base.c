/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_nbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:04:40 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/07 03:06:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_print.h"
#include "f_math.h"

static void	print_nbr_rec(int fd, unsigned int unbr, unsigned int base)
{
	if (unbr > 0)
	{
		print_nbr_rec(fd, unbr / 10);
		f_print_char_fd(fd, (unbr % 10) + '0');
	}
}

void		f_print_nbr_fd(int fd, int nbr, unsigned int base)
{
	unsigned int	unbr;

	if (fd < 0)
		return ;
	if (nbr == 0)
	{
		f_print_char_fd(fd, '0');
		return ;
	}
	if (nbr < 0)
		f_print_char_fd(fd, '-');
	unbr = f_abs(nbr);
	print_nbr_rec(fd, unbr);
}

void		f_print_nbr(int nbr)
{
	f_print_nbr_fd(1, nbr);
}
