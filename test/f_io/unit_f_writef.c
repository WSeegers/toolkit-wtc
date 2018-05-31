/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_f_writef.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:04:05 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 16:41:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "utest.h"
#include "f_io.h"

static int	fail_basic(void)
{
	t_file *file_w;
	t_file *file_r;
	char 	buf_w[] = "This is the most amazing test";
	char	buf_r[100];
	int		len;
	int		ret;

	ret = 0;
	len = strlen(buf_w) + 1;
	file_w = f_openf("txt/basic_write_test.txt", 'w');
	file_r = f_openf("txt/basic_write_test.txt", 'r');
	f_writef(file_w, buf_w, len);
	f_readf(buf_r, file_r, len);
	if (memcmp(buf_w, buf_r, len))
		ret = 1;
	close(file_w->fd_out);
	close(file_w->fd_in);
	return (ret);
}

void	unit_f_writef(void)
{
	t_unit *unit;

	unit = create_unit ("f_writef");

	add_test(unit, create_test("basic write test", 1, fail_basic));

	run_unit(unit, NULL, true);
}
