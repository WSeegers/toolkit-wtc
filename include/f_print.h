/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:41:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/27 17:42:33 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINT_H
# define F_PRINT_H

ssize_t	f_print_str_fd(int fd, char *str);
ssize_t f_print_str(char *str);
ssize_t f_print_err(char *str);

#endif
