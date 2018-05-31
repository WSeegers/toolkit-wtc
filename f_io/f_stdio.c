/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_stdio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:08:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 16:09:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_print.h"
#include "s_file.h"

t_file	*f_stdio(int std_fd)
{
	static t_file	stdi;
	static t_file	stdo;
	static t_file	stde;

	stdi = (t_file)STDIN_;
	stdo = (t_file)STDOUT_;
	stde = (t_file)STDERR_;

	if (std_fd == 0)
		return (&stdi);
	if (std_fd == 1)
		return (&stdo);
	if (std_fd == 2)
		return (&stde);
	f_print_err("f_stdio.c: std_fd must be 0, 1, 2");
	return (NULL);	
}
