/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_io.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:35:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 20:26:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_IO_H
# define F_IO_H

# include <unistd.h>
# include <stddef.h>
# include "s_file.h"

t_file	*f_openf(char *path, char mode);
ssize_t	f_readf(char *ptr, t_file *file, size_t n);
ssize_t	f_writef(t_file *file, char *ptr, size_t n);
void	f_close(t_file *file);

#endif
