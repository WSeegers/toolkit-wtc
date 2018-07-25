/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:37:21 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:18:18 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_dstr.h"
#include "f_print.h"

ssize_t	print_dstr_fd(int fd, t_dstr *dstr)
{
	return (f_print_str_fd(fd, dstr->str));
}

ssize_t	print_dstr(t_dstr *dstr)
{
	return (f_print_str(dstr->str));
}

ssize_t	print_dstr_err(t_dstr *dstr)
{
	return (f_print_err(dstr->str));
}
