/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:41:46 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/04 17:46:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

char			**ft_strsplit(char const *s, char c);

int main(void)
{

	char **splits;
	
	splits =  ft_strsplit("this,is,a,spliting,program\n", ',');

	while (*splits)
		puts(*splits++);

}
