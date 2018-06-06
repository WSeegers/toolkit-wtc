/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:36:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 11:02:54 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_STRING_H
# define F_STRING_H

# include <stddef.h>

size_t	f_strlen(const char *str);
char	*f_strjoin(char const *s1, char const *s2);
char	*f_strcpy(char *dest, const char *src);
int		f_strcmp(const char *s1, const char *s2);
int		f_strncmp(const char *s1, const char *s2, size_t n);
char	*f_strnew(size_t n);
void	f_strdel(char **as);
char	*f_strdup(const char *s);
size_t	f_strlcat(char *dest, const char *src, size_t size);
size_t	f_strnlen(const char *s, size_t maxlen);
char	*f_strresize(char **old, size_t n);
char	*f_strncpy(char *dest, const char *src, size_t n);
char	*f_strchr(const char *s, int c);
char	*f_strstr(const char *haystack, const char *needle);
long	f_strtol(const char *nptr, char **endptr, int base);
int		f_atoi(const char *nptr);
int		f_islower(int c);
int		f_toupper(int c);
int		f_isblank(int c);
int		f_isspace(int c);
int		f_isdigit(int c);

#endif
