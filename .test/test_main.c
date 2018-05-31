/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:57:33 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 16:03:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test_main.h"

int main(void)
{
	printf("Tookit test starting..\n\n");
	unit_f_initf();
	unit_f_openf();
	unit_f_readf();
	unit_f_writef();
	printf("\n\nTest end..\n");
	return (0);
}
