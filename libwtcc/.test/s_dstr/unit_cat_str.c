/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_cat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:00:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 19:41:32 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utest.h"
#include "s_dstr.h"
#include <string.h>

static int basic_test(void)
{
	char test[200] = "this is a string";
	char cat[] = "...cat";
	t_dstr *dstr;

	dstr = new_dstr(test);
	cat_str(dstr, cat);
	strcat(test, cat);
	if (strcmp(dstr->str, test))
		return (1);
	else
		return (0);
}

static int mcat_test(void)
{
	char test[500] = "this is a string";
	char cat[] = "...cat";
	t_dstr *dstr;

	dstr = new_dstr(test);
	for (int i = 0; i < 10; i++)
	{
		cat_str(dstr, cat);
		strcat(test, cat);
	}
	if (strlen(test) != dstr->len)
		return (1);
	else
		return (0);
}

void	unit_cat_str(void)
{
	t_unit *unit;

	unit = create_unit ("cat_str");

	add_test(unit, create_test("failed basic cat", 1, basic_test));
	add_test(unit, create_test("failed multiple cat", 1, mcat_test));
	run_unit(unit, NULL, true);
}
