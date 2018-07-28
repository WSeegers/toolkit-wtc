/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:00:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/28 05:20:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "f_print.h"
#include <limits.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
	int i;

	setlocale (LC_ALL, "");
	f_printf("FT :%C\n", 0);
	  printf("FT :%C\n", 0);
	fflush(NULL);

	f_printf("FT :%s\n", "abc");
	  printf("SYS:%s\n", "abc");
	fflush(NULL);

	f_printf("FT :%lc, %lc\n", L'暖', L'ح');
	  printf("SYS:%lc, %lc\n", L'暖', L'ح');
	fflush(NULL);

	f_printf("FT :%#X\n", 42);
	  printf("SYS:%#X\n", 42);
	fflush(NULL);

}
