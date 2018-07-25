/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_cut_dstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:00:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 20:29:31 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utest.h"
#include "s_dstr.h"
#include <string.h>

static int return_test(void)
{
	char test[] = "this is a string";
	t_dstr *dstr;
	t_dstr *cut;

	dstr = new_dstr(test);
	cut = cut_dstr(dstr, 0, 4);
	if (strcmp(cut->str, "this"))
		return (1);
	else
		return (0);
}

static int leftover_test(void)
{
	char test[] = "this is a string";
	t_dstr *dstr;

	dstr = new_dstr(test);
	cut_dstr(dstr, 0, 4);
	if (strcmp(dstr->str, " is a string"))
		return (1);
	else
		return (0);
}

static int back_test(void)
{
	char test[] = "this is a string";
	t_dstr *dstr;

	dstr = new_dstr(test);
	cut_dstr(dstr, -6, 0);
	if (strcmp(dstr->str, "this is a "))
		return (1);
	else
		return (0);
}

static int mid_cut_test(void)
{
	char test[] = "this is a string";
	t_dstr *dstr;

	dstr = new_dstr(test);
	cut_dstr(dstr, 4, 6);
	if (strcmp(dstr->str, "thisstring"))
		return (1);
	else
		return (0);
}

static int mid_return_test(void)
{
	char test[] = "this is a string";
	t_dstr *dstr;
	t_dstr *cut;

	dstr = new_dstr(test);
	cut = cut_dstr(dstr, 4, 6);
	if (strcmp(cut->str, " is a "))
		return (1);
	else
		return (0);
}

void	unit_cut_dstr(void)
{
	t_unit *unit;

	unit = create_unit ("cut_str");

	add_test(unit, create_test("return is incorrect", 1, return_test));
	add_test(unit, create_test("remaining string is incorrect", 1, leftover_test));
	add_test(unit, create_test("reverse cut is incorrect", 1, back_test));
	add_test(unit, create_test("mid string cut failed", 1, mid_cut_test));
	add_test(unit, create_test("mid string cut return failed", 1, mid_return_test));
	run_unit(unit, NULL, true);
}
