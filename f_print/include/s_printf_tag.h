/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf_tag.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:56:38 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/07 04:34:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PRINTF_TAGS_H
# define S_PRINTF_TAGS_H

# include <stdbool.h>
# include <stddef.h>

# define SIZE_NONE 0
# define SIZE_CHAR 1
# define SIZE_SHORT 2
# define SIZE_LONG 3
# define SIZE_LLONG 4
# define SIZE_IMAX 5
# define SIZE_T 6

# define SPECS "sSpdDioOuUxXcCeEfFgGaAn"
# define NBR_SPEC "pdDioOuUxX"
# define STR_SPEC "sScC"
# define FLT_SPEC "eEfFgGaA"
# define OTH_SPEC "n%"

typedef struct	s_tag
{
	char		spec;

	bool		left_just;
	bool		force_sign;
	bool		space;
	bool		expanded;
	bool		pad;

	size_t		min_len;
	bool		va_width;

	size_t		precision;
	bool		va_prec;
	
	int			mem_size;
	
	const char 	*format;
}				t_tag;

void	init_tag(t_tag *tag);
char	*get_tag(const char *format);
t_tag	*parse_tag(const char *format);
size_t	write_till_tag(int fd, const char *format);
char	*get_tag(const char *format);

#endif
