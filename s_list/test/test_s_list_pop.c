/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s_list_pop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:19:13 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/28 12:54:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"
#include "f_print.h"
#include "f_string.h"
#include "f_memory.h"

int 	test1(void)
{
	char *data[4];
	t_list *list;
	void *data_pop;
	int i;

	data[0] = f_strdup("asdfl;jhasdf;\n");
	data[1] = f_strdup("asdfl;jhasf;d&*\n");
	data[2] = f_strdup("asdfl;kj;ohjasf8\n");
	data[3] = f_strdup("jkeasdfgniodsf\n");
	list = s_list_create(NULL);
	i = -1;
	while (++i < 4)
		s_list_append(list,	data[i]);
	i = -1;
	f_print_str("\n");
	while (++i < 4)
	{
		data_pop = s_list_pop(list, 0);
		if (f_memcmp(data_pop, data[i], f_strlen(data[i])))
				return (0);
		f_memdel(&data_pop);
	}
	if (list->tail || list->head)
		return (0);
	s_list_clear(list);
	return (1);
}

int 	test2(void)
{
	char *data[4];
	t_list *list;
	void *data_pop;
	int i;

	data[0] = f_strdup("0 asdfl;jhasdf;");
	data[1] = f_strdup("1 asdfl;jhasf;d&*");
	data[2] = f_strdup("2 asdfl;kj;ohjasf8");
	data[3] = f_strdup("3 jkeasdfgniodsf");
	list = s_list_create(NULL);
	i = -1;
	while (++i < 4)
		s_list_append(list,	data[i]);
	i = 4;
	while (i--)
	{
		data_pop = s_list_pop(list, -1);
		if (f_memcmp(data_pop, data[i], f_strlen(data[i])))
				return (0);
		f_memdel(&data_pop);
	}
	if (list->tail || list->head)
		return (0);
	s_list_clear(list);
	return (1);
}

int		main(void)
{
	int		(*test[])(void) = {
		&test1, 
		&test2,
		NULL};
	int i  = -1;

	f_print_str("s_list_create:");	
	while (test[++i])
		if (test[i]())
			f_print_str(" [PASS]");
		else
			f_print_str(" [FAIL]");
	f_print_str("\n");
	return (0);	
}
