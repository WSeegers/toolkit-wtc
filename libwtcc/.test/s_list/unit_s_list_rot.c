/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_s_list_rot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:45:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 19:59:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "utest.h"
#include "s_list.h"

int 	rot_fw1(void)
{
	char data[] = "hello this is data";
	t_list *list;
	int	ret;

	ret = 0;
	list = s_list_create(NULL);
	s_list_append(list, "one");
	s_list_append(list, data);
	s_list_append(list, "three");
	s_list_rot(list, 1);
	if (strcmp(s_list_pop(list, 0), data))
		ret = 1;
	s_list_clear(list);
	return (ret);
}

int 	rot_fw9(void)
{
	char data[] = "hello this is data";
	t_list *list;
	int	ret;

	ret = 0;
	list = s_list_create(NULL);
	s_list_append(list, "one");
	s_list_append(list, data);
	s_list_append(list, "three");
	s_list_rot(list, 9);
	if (strcmp(s_list_pop(list, 1), data))
		ret = 1;
	s_list_clear(list);
	return (ret);
}

void	unit_s_list_rot(void)
{
	t_unit *unit;

	unit = create_unit ("s_list_rot");

	add_test(unit, create_test("rotate forward x1", 1, rot_fw1));
	add_test(unit, create_test("rotate forward x9", 1, rot_fw9));
	//add_test(unit, create_test("inserting at back", 1, insert_at_back));
	//add_test(unit, create_test("inserting in front", 1, insert_in_front));

	run_unit(unit, NULL, true);
}
