/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_f_initf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:05:55 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 15:57:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utest.h"
#include "f_io.h"

static int	basic(void)
{
	t_file *file;

	file = (t_file*)malloc(sizeof(*file));
	f_initf(file, "txt/text1.txt", 'r');
	if (file->fd_in == -2)
		return(1);
	close(file->fd_in);
	return (0);
}

static	int	read_test(void)
{
	t_file *file;
	char 	buf[20];
	char 	*test = "A long time";

	file = (t_file*)malloc(sizeof(*file));
	f_initf(file, "txt/text1.txt", 'r');
	read(file->fd_in, buf, 20);

	if (memcmp(buf, test, strlen(test)))
		return (1);
	return (0);
}

void	unit_f_initf(void)
{
	t_unit *unit;

	unit = create_unit ("f_initf");

	add_test(unit, create_test("Basic parm test", 1, basic));
	add_test(unit, create_test("Test for read functionality", 1, read_test));
	
	run_unit(unit, NULL, true);
}

