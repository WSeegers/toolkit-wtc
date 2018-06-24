/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cntl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 08:46:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/24 08:52:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_CNTL_H
# define F_CNTL_H

void	f_exit(int code);
void	f_eexit(int code, char *s);
t_list	*f_memlist(void);

#endif
