/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 06:52:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 12:18:08 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DSTR_H
# define S_DSTR_H

# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>

# define DSTR_INIT_SIZE (32)


typedef struct	s_dstr
{
	char	*str;
	size_t	len;
	size_t 	cap;
}				t_dstr;

typedef long long t_index;

t_dstr	*init_dstr(size_t cap);
t_dstr	*new_dstr(char *str);
size_t	recap_dstr(t_dstr *str, size_t len);
bool	capchk_dstr(t_dstr *str, size_t len);
bool	isempty_dstr(t_dstr *str);
size_t	len_dstr(t_dstr *dstr);
void	cat_str(t_dstr *dstr, char *str);
void	ncat_str(t_dstr *dstr, char *str, size_t n);
void	cat_dstr(t_dstr *dest, t_dstr *src);
void	ncat_dstr(t_dstr *dest, t_dstr *src, size_t n);
void	merge_dstr(t_dstr *dest, t_dstr *src);
t_index	find_dstr(t_dstr *dstr, char *needle);
t_dstr	*cut_dstr(t_dstr *dstr, t_index start, size_t size);
void	del_dstr(t_dstr **dstr);

ssize_t	print_dstr_fd(int fd, t_dstr *dstr);
ssize_t	print_dstr(t_dstr *dstr);
ssize_t	print_dstr_err(t_dstr *dstr);

#endif
