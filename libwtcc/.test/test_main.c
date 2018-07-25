/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:57:33 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 20:02:06 by wseegers         ###   ########.fr       */
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
	unit_f_next_line();

	unit_s_list_insert();
	unit_s_list_rot();

	unit_new_dstr();
	unit_cat_str();
	unit_find_dstr();
	unit_cut_dstr();
	printf("\n\nTest end..\n");
	return (0);
}
