/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_new_dstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:00:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 19:32:27 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utest.h"
#include "s_dstr.h"
#include <string.h>

static int content_test(void)
{
	char test[] = "this is a string";
	t_dstr *dstr;

	dstr = new_dstr(test);
	if (strcmp(dstr->str, test))
		return (1);
	else
		return (0);
}

static int len_test(void)
{
	char test[] = "this is a string";
	t_dstr *dstr;

	dstr = new_dstr(test);
	if (strlen(test) != dstr->len)
		return (1);
	else
		return (0);
}

void	unit_new_dstr(void)
{
	t_unit *unit;

	unit = create_unit ("new_dstr");

	add_test(unit, create_test("string content is incorrect", 1, content_test));
	add_test(unit, create_test("dstr has incorrect len member", 1, len_test));
	run_unit(unit, NULL, true);
}
