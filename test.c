/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:00:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/12 07:17:17 by wseegers         ###   ########.fr       */
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

	//setlocale (LC_ALL, "");
	for (int k = 1; k > 0; k++)
	{
	f_printf("ft: ");
	f_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	f_printf("\n");
	}
	//printf("sy: ");
	//printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	//printf("\n");
}
