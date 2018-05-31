/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:41:29 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 20:27:28 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINT_H
# define F_PRINT_H

# include <unistd.h>

ssize_t		f_print_str_fd(int fd, char *str);
ssize_t		f_print_str(char *str);
ssize_t		f_print_err(char *str);

void		f_print_nbr_fd(int fd, int nbr);
void		f_print_nbr(int nbr);

ssize_t		f_print_char_fd(int fd, char c);
ssize_t		f_print_char(char c);
#endif
