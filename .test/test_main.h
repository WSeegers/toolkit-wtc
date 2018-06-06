/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:58:27 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 20:01:25 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MAIN_H
# define TEST_MAIN_H

# include "utest.h"

void	unit_f_initf(void);
void	unit_f_openf(void);
void	unit_f_readf(void);
void	unit_f_writef(void);
void	unit_f_next_line(void);

void	unit_s_list_insert(void);
void	unit_s_list_rot(void);

void	unit_new_dstr(void);
void	unit_cat_str(void);
void	unit_find_dstr(void);
void	unit_cut_dstr(void);
#endif
