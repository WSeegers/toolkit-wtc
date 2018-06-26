/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_matrix_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 07:06:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/26 07:41:35 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_matrix.h"

t_matrix4	s_matrix_mul(t_matrix4 m1, t_matrix4 m2)
{
	t_matrix4 ret;
	int row;
	int col;
	int i;

	ret = s_matrix4_create();	
	int row = -1;
	while (++row < 4 && col = -1)
		while (++col < 4 && i = -1)
			while (++i < 4)
				ret[row][col] += m1[row][i] * m2[i][col];
	return (ret);
}

#include <stdio.h>

int main(void)
{
	t_matrix4 m1, m2, m3;

	m1 = s_matrix4_create();
	m2 = s_matrix4_create();
	
	m3 = s_matrix_mul(m1, m2);

	for (int i = 0; i < 4; i++)
	{
		printf("|");
		for (int j = 0; j < 4; j++)
		{
			printf(" %f |", m3[i][j]); 
		}
		printf("\n");
	}
}
