/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:00:50 by WSeegers          #+#    #+#             */
/*   Updated: 2018/05/23 11:06:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	size_t	i;

	chr = (char)c;
	i = -1;
	while (s[++i] != chr)
		if (!s[i])
			return (NULL);
	return ((char*)(s + i));
}
