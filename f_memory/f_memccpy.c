/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memccpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:44:17 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/27 17:22:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*f_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;
	unsigned char *d;
	unsigned char *s;

	i = -1;
	while (++i < n)
	{
		*d++ = *s++;
		if (d[-1] == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
