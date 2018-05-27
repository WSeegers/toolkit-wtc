/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:38:02 by WSeegers          #+#    #+#             */
/*   Updated: 2018/04/24 12:27:53 by WSeegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len_n;

	if (!*needle)
		return ((char*)haystack);
	len_n = ft_strlen(needle);
	while (*haystack && ft_strncmp(haystack, needle, len_n))
		haystack++;
	if (*haystack)
		return ((char*)haystack);
	return (NULL);
}
