/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:00:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/30 15:22:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "f_print.h"
#include <limits.h>
#include <locale.h>
#include <stdlib.h>
#include "term_colours.h"

enum colour 
{
	black,
	white,
	yellow
};

int main(void)
{
	int i;

	setlocale (LC_ALL, "");
	f_printf("FT :{%S}\n", L"我是一只猫。");
	  printf("SYS:{%S}\n", L"我是一只猫。");
	fflush(NULL);

	f_printf("FT :%10R\n");
	  printf("SYS:%10R\n");
	fflush(NULL);

	f_printf("FT :%05s\n", "This is a string");
	  printf("SYS:%05s\n", "This is a string");
	fflush(NULL);

	f_printf("FT :%-20s\n", "This is a string");
	  printf("SYS:%-20s\n", "This is a string");
	fflush(NULL);

	f_printf("FT :%-10.5s\n", "This is a string");
	  printf("SYS:%-10.5s\n", "This is a string");
	fflush(NULL);

	f_printf("FT :%lc, %lc\n", L'暖', L'ح');
	  printf("SYS:%lc, %lc\n", L'暖', L'ح');
	fflush(NULL);

	f_printf("FT :%#X\n", 42);
	  printf("SYS:%#X\n", 42);
	fflush(NULL);

}
