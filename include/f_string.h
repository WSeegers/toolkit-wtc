/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:36:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 09:53:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_STRING_H
# define F_STRING_H

#include <stddef.h>

size_t	f_strlen(const char *str);
int		f_strcmp(const char *s1, const char *s2);
char	*f_strnew(size_t n);
void	f_strdel(char **as);
char	*f_strdup(const char *s);
size_t	f_strlcat(char *dest, const char *src, size_t size);
size_t	f_strnlen(const char *s, size_t maxlen);

#endif
