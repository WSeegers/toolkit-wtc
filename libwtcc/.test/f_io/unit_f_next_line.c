/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_f_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:56:03 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/06 17:03:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "utest.h"
#include "f_io.h"

static int	basic_test(void)
{
	t_file *file;
	char 	buf[10000];
	char 	*nl;
	ssize_t	len;
	int		ret;
	int 	fd;

	ret = 0;
	file = f_openf("txt/200kb.txt", 'r');
	fd = open("txt/200kb.txt", O_RDONLY);
	len = f_next_line(&nl, file);
	read(fd, buf, len);
	if (memcmp(nl, buf, len - 1))
		ret = 1;
	close(file->fd_out);
	close(fd);
	return (ret);
}

static int	line2_test(void)
{
	t_file *file;
	char 	buf[10000];
	char 	*nl;
	ssize_t	len;
	int		ret;
	int 	fd;

	ret = 0;
	file = f_openf("txt/200kb.txt", 'r');
	fd = open("txt/200kb.txt", O_RDONLY);
	len = f_next_line(&nl, file);
	read(fd, buf, len);
	len = f_next_line(&nl, file);
	read(fd, buf, len);
	if (memcmp(nl, buf, len - 1))
		ret = 1;
	close(file->fd_out);
	close(fd);
	return (ret);
}

static int	f200kb_test(void)
{
	t_file *file;
	char 	buf[10000];
	char 	*nl;
	ssize_t	len;
	int		ret;
	int 	fd;

	ret = 0;
	file = f_openf("txt/200kb.txt", 'r');
	fd = open("txt/200kb.txt", O_RDONLY);
	while((len = f_next_line(&nl, file)))
	{
		read(fd, buf, len);
		if (memcmp(nl, buf, len - 1))
		{
			ret = 1;
			break ;
		}
	}
	close(file->fd_out);
	close(fd);
	return (ret);
}

void	unit_f_next_line(void)
{
	t_unit *unit;

	unit = create_unit ("f_next_line");

	add_test(unit, create_test("basic operation of function", 1, basic_test));
	add_test(unit, create_test("double operation of function", 1, line2_test));
	add_test(unit, create_test("complete file 200kb", 1, f200kb_test));
	run_unit(unit, NULL, true);
}
