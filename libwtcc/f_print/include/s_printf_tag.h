/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf_tag.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:56:38 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/10 13:25:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PRINTF_TAG_H
# define S_PRINTF_TAG_H

# include <stdbool.h>
# include <stddef.h>
# include <stdarg.h>

# define SPECS "sSpdDioOuUxXcCeEfFgGaAn"
# define INT_SPEC "pdDioOuUxX"
# define STR_SPEC "sScC"
# define FLT_SPEC "eEfFgGaA"
# define OTH_SPEC "n%"

typedef struct	s_tag
{
	char		spec;

	bool		left_just;
	bool		force_sign;
	bool		space;
	bool		prefix;
	bool		zeropad;
	bool		sep;

	size_t		min_width;
	bool		va_width;

	size_t		precision;
	bool		va_prec;

	size_t		mem_size;

	const char	*format;
}				t_tag;

void			init_tag(t_tag *tag);
char			*get_tag(const char *format);
t_tag			*parse_tag(const char *format);
char			*get_tag(const char *format);
int				s_tag_get_prec(t_tag *tag, va_list ap);
int				s_tag_get_width(t_tag *tag, va_list ap);

#endif
