/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_math.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:53:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/07/16 11:35:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_MATH_H
# define F_MATH_H

# define MIN(n1, n2)    (n1 < n2) ? n1 : n2
# define MAX(n1, n2)    (n1 > n2) ? n1 : n2

long long	f_abs(long long nbr);
long		f_min(long base, long test);
long		f_max(long base, long test);

#endif
