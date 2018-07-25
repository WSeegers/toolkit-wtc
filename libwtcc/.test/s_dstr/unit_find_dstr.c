/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_find_dstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:00:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 20:02:28 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utest.h"
#include "s_dstr.h"
#include <string.h>

static int basic_test(void)
{
	char test[] = "this is a%string";
	t_dstr *dstr;

	dstr = new_dstr(test);
	if (strcmp(dstr->str + find_dstr(dstr, "%"), strchr(test, '%')))
		return (1);
	else
		return (0);
}

static int fail_test(void)
{
	char test[] = "this is a string";
	t_dstr *dstr;

	dstr = new_dstr(test);
	if (find_dstr(dstr, "%") != -1)
		return (1);
	else
		return (0);
}

void	unit_find_dstr(void)
{
	t_unit *unit;

	unit = create_unit ("find_dstr");

	add_test(unit, create_test("failed basic find", 1, basic_test));
	add_test(unit, create_test("no find returned wrong value", 1, fail_test));
	run_unit(unit, NULL, true);
}
