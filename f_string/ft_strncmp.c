/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:30:26 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/24 14:05:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!n)
		return (0);
	i = 1;
	while (*s1 == *s2)
	{
		if (!*s1++ || i++ == n)
			return (0);
		s2++;
	}
	return ((t_uchar)(*s1) - (t_uchar)(*s2));
}
