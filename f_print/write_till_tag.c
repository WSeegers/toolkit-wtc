/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_till_tag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:22:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 23:52:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "f_string.h"
#include "f_print.h"
#include "include/s_printf_tag.h"

size_t write_till_tag(int fd, const char *format)
{
	char *tag;

	if ((tag = get_tag(format)) && tag > format)
		return (write(fd, format, f_strchr(format, '%') - format));
	else
		return (f_print_str_fd(fd, format));
}
