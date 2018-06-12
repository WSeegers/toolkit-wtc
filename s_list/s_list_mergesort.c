/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_mergesort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:48:45 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/12 13:13:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list.h"
#include "f_print.h"

static void	split_list(t_list *list, t_list *listA, t_list *listB)
{
	int		i;
	void	*data;

	i = 1;
	while ((data = s_list_pop(list, 0)))
	{
		if (i)
		{
			s_list_append(listA, data);
			i = 0;
		}
		else
		{
			s_list_append(listB, data);
			i = 1;
		}
	}
}

static void merge_lists(t_list *sorted, t_list *listA, t_list *listB,
												int (*f_data_cmp)(void*, void*))
{
	void *dataA;
	void *dataB;
	
	dataA = s_list_pop(listA, 0);
	dataB = s_list_pop(listB, 0);
	while (dataA && dataB)
	{
		if (f_data_cmp(dataA, dataB) < 0)
		{
			s_list_append(sorted, dataB);
			dataB = s_list_pop(listB, 0);
			continue ;
		}
		s_list_append(sorted, dataA);
		dataA = s_list_pop(listA, 0);
	}
	while (dataA)
	{
		s_list_append(sorted, dataA);
		dataA = s_list_pop(listA, 0);
	}
	while (dataB)
	{
		s_list_append(sorted, dataB);
		dataB = s_list_pop(listB, 0);
	}
}

void		s_list_mergesort(t_list *list, int (*f_data_cmp)(void*, void*))
{
	t_list *listA;
	t_list *listB;
	
	if (list && list->size > 1)
	{
		listA = s_list_create(NULL);
		listB = s_list_create(NULL);
		split_list(list, listA, listB);
		s_list_mergesort(listA, f_data_cmp);
		s_list_mergesort(listB, f_data_cmp);
		merge_lists(list, listA, listB, f_data_cmp);
	}
}
