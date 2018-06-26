/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_matrix.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 06:36:26 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/26 07:45:30 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MATRIX_H
# define S_MATRIX_H

typedef double *t_matrix4;

t_matrix4	s_matrix4_create(void);
void		s_matrix4_initid(t_matrix4 m);
t_matrix4	s_matrix4_mul(t_matrix4 m1, t_matrix4 m2);
void		s_matrix4_transf(t_matrix4 m1, t_matrix4 m2);

typedef double *t_matrix3;

t_matrix3	s_matrix3_create(void);
void		s_matrix3_initid(t_matrix3 m);
t_matrix3	s_matrix3_mul(t_matrix3 m1, t_matrix3 m2);
void		s_matrix3_transf(t_matrix3 m1, t_matrix3 m2);

#endif
