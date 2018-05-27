/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:56:45 by WSeegers          #+#    #+#             */
/*   Updated: 2018/04/23 16:57:43 by WSeegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t ret;

	i = ft_strnlen(dest, size);
	ret = i + ft_strlen(src);
	if (i == size)
		return (ret);
	while (*src && i < size)
		dest[i++] = *src++;
	if (i == size)
		i--;
	dest[i] = '\0';
	return (ret);
}
