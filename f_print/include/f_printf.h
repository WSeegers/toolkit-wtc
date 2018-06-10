/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:06:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 13:23:52 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINTF_H
# define F_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include "s_printf_tag.h"

# define PF_BUFFSIZE 512

int	pf_nbrtostr(long long nbr, char *str, unsigned int base,
													unsigned int min_width);
int	pf_unbrtostr(unsigned long long unbr, char *str, unsigned int base,
													unsigned int min_width);
int	pf_ftostr(long double nbr, char *str, unsigned int precision);
int	pf_wstrtostr(char *buf, int *wstr, size_t n);
int	pf_wctostr(char *buf, int c);
int	pf_padding(char *buf, t_tag *tag, size_t n);
int	pf_handle_str(char *buf, t_tag *tag, va_list ap, size_t n);
int	pf_handle_int(char *buf, t_tag *tag, va_list ap, size_t n);

#endif
