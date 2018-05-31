/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 06:52:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/30 07:11:08 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DSTR
# define S_DSTR

# include <stddef.h>

# define DSTR_INIT_SIZE (8 * 4)

typedef struct	s_dstr
{
	char	*str;
	size_t	len;
	size_t 	cap;
}				t_dstr;

t_dstr	*init_str(size_t capacity);
t_dstr	*new_str(char *str);

# define S_DSTR
