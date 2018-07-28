/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:00:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/28 02:06:03 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "f_print.h"
#include <limits.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
	ft_printf("FT :%#.o %#.0o\n", 0, 0);
	   printf("SYS:%#.o %#.0o\n", 0, 0);
	fflush(NULL);
	f_printf("FT :%#llX\n", 922337203685477);
	printf(  "SYS:%#llX\n", 922337203685477);
	fflush(NULL);
	f_printf("FT :%#-x\n", 23);
	printf(  "SYS:%#x\n", 23);
	fflush(NULL);
	f_printf("FT : |%.o|---|%#.x|\n", 0, 0);
	printf(  "SYS: |%.o|---|%#.x|\n", 0, 0);
	fflush(NULL);
}

