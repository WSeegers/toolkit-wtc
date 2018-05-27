/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:10:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/23 11:06:40 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*start;
	char	*ret;
	size_t	len;

	if (!s)
		return (NULL);
	while (iswhitespace(*s))
		s++;
	if (!*s)
		return (ft_strdup(""));
	start = (char*)s;
	len = 1;
	while (*++s)
		len++;
	while (iswhitespace(*--s))
		len--;
	if (!(ret = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(ret, start, len));
}
