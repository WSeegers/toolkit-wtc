/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_swapptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:01:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/17 23:49:57 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	f_swapptr(void **p1, void **p2)
{
	void *temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
