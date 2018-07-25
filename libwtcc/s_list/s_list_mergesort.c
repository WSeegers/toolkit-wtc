/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_mergesort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:48:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/18 12:51:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"
#include "f_print.h"

static void	split_list(t_list *list, t_list *list_a, t_list *list_b)
{
	int		i;
	void	*data;

	i = 1;
	while ((data = s_list_pop(list, 0)))
	{
		if (i)
		{
			s_list_append(list_a, data);
			i = 0;
		}
		else
		{
			s_list_append(list_b, data);
			i = 1;
		}
	}
}

static void	merge_lists(t_list *sorted, t_list *list_a, t_list *list_b,
												int (*f_data_cmp)(void*, void*))
{
	void *data_a;
	void *data_b;

	data_a = s_list_pop(list_a, 0);
	data_b = s_list_pop(list_b, 0);
	while (data_a && data_b)
	{
		if (f_data_cmp(data_a, data_b) < 0)
		{
			s_list_append(sorted, data_b);
			data_b = s_list_pop(list_b, 0);
			continue ;
		}
		s_list_append(sorted, data_a);
		data_a = s_list_pop(list_a, 0);
	}
	while (s_list_append(sorted, data_a))
		data_a = s_list_pop(list_a, 0);
	while (s_list_append(sorted, data_b))
		data_b = s_list_pop(list_b, 0);
}

void		s_list_mergesort(t_list *list, int (*f_data_cmp)(void*, void*))
{
	t_list *list_a;
	t_list *list_b;

	if (list && list->size > 1)
	{
		list_a = s_list_create(NULL);
		list_b = s_list_create(NULL);
		split_list(list, list_a, list_b);
		s_list_mergesort(list_a, f_data_cmp);
		s_list_mergesort(list_b, f_data_cmp);
		merge_lists(list, list_a, list_b, f_data_cmp);
	}
}
