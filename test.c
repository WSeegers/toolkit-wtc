/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:00:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/09 17:31:48 by wseegers         ###   ########.fr       */
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
	char c;

	setlocale (LC_ALL, "");

	printf("sy: ");
	printf("{%10d}", 42);
	puts("...");
	f_printf("ft: ");
	f_printf("{%10d}", 42);
	puts("...");
}
