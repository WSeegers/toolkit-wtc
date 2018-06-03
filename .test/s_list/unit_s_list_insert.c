/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_s_list_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:07:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/03 19:49:06 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "utest.h"
#include "s_list.h"

int 	basic_test(void)
{
	char data[] = "hello this is data";
	t_list *list;
	int	ret;

	ret = 0;
	list = s_list_create(NULL);
	s_list_append(list, "one");
	s_list_append(list, "two");
	s_list_append(list, "three");
	s_list_insert(list, data, 1);
	if (strcmp(s_list_pop(list, 1), data))
		ret = 1;
	s_list_clear(list);
	return (ret);
}

int 	insert_at_back(void)
{
	char data[] = "hello this is data";
	t_list *list;
	int	ret;

	ret = 0;
	list = s_list_create(NULL);
	s_list_append(list, "one");
	s_list_append(list, "two");
	s_list_append(list, "three");
	s_list_insert(list, data, -1);
	if (strcmp(s_list_pop(list, -1), data))
		ret = 1;
	s_list_clear(list);
	return (ret);
}

int 	insert_in_front(void)
{
	char data[] = "hello this is data";
	t_list *list;
	int	ret;

	ret = 0;
	list = s_list_create(NULL);
	s_list_append(list, "one");
	s_list_append(list, "two");
	s_list_append(list, "three");
	s_list_insert(list, data, 0);
	if (strcmp(s_list_pop(list, 0), data))
		ret = 1;
	s_list_clear(list);
	return (ret);
}


void	unit_s_list_insert(void)
{
	t_unit *unit;

	unit = create_unit ("s_list_insert");

	add_test(unit, create_test("basic operation of function", 1, basic_test));
	add_test(unit, create_test("inserting at back", 1, insert_at_back));
	add_test(unit, create_test("inserting in front", 1, insert_in_front));

	run_unit(unit, NULL, true);
}

