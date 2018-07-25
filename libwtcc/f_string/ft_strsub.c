/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:54:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/23 21:01:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, t_uint start, size_t len)
{
	char	*ret;
	t_uint	i;

	if (!str || !(ret = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = str[start + i];
	return (ret);
}
