/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_f_readf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:19:47 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/31 16:00:14 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "utest.h"
#include "f_io.h"

static int	fail_test1(void)
{
	t_file *file;
	char 	buf[20];
	int		ret;

	ret = 0;
	file = f_openf("txt/fail_test.txt", 'w');
	if (f_readf(buf, file, 20) != -1)
		ret = 1;
	close(file->fd_in);
	return (ret);
}

static	int	read_test_simple(void)
{
	t_file *file;
	char 	buf1[20];
	int 	fd;
	char	buf2[20];
	int		ret;
	
	ret = 0;
	file = f_openf("txt/text1.txt", 'r');
	fd = open("txt/text1.txt", O_RDONLY);
	f_readf(buf1, file, 20);
	read(fd, buf2, 20);
	if (memcmp(buf1, buf2, 20))
		ret = 1;
	close(fd);
	close(file->fd_in);
	return (ret);
}

static	int	read_test_small_file(void)
{
	t_file *file;
	char 	buf1[20];
	int 	fd;
	char	buf2[20];
	int		ret;
	int 	read_;
	
	ret = 0;
	file = f_openf("txt/text1.txt", 'r');
	fd = open("txt/text1.txt", O_RDONLY);
	while (!ret && (read_ = f_readf(buf1, file, 20)))
	{
		read(fd, buf2, 20);
		if (memcmp(buf1, buf2, 20))
		{	
			ret = 1;
			break ;
		}
	}
	close(fd);
	close(file->fd_in);
	return (ret);
}

static	int	read_test_200kb_file(void)
{
	t_file *file;
	char 	buf1[20];
	int 	fd;
	char	buf2[20];
	int		ret;
	
	ret = 0;
	file = f_openf("txt/200kb.txt", 'r');
	fd = open("txt/200kb.txt", O_RDONLY);
	while (!ret && f_readf(buf1, file, 20))
	{
		read(fd, buf2, 20);
		if (memcmp(buf1, buf2, 20))
		{
			ret = 1;
			break ;
		}
	}
	close(fd);
	close(file->fd_in);
	return (ret);
}

static	int	read_test_1000kb_file(void)
{
	t_file *file;
	char 	buf1[20];
	int 	fd;
	char	buf2[20];
	int		ret;
	
	ret = 0;
	file = f_openf("txt/1000kb.txt", 'r');
	fd = open("txt/1000kb.txt", O_RDONLY);
	while (!ret && f_readf(buf1, file, 20))
	{
		read(fd, buf2, 20);
		if (memcmp(buf1, buf2, 20))
		{
			ret = 1;
			break ;
		}
	}
	close(fd);
	close(file->fd_in);
	return (ret);
}

void	unit_f_readf(void)
{
	t_unit *unit;

	unit = create_unit ("f_readf");

	add_test(unit, create_test("f_readf should return  == -1", 1, fail_test1));
	add_test(unit, create_test("Test for read functionality", 0, read_test_simple));
	add_test(unit, create_test("Test reading a small file in a loop", 2,
															read_test_small_file));
	add_test(unit, create_test("Test reading a 200kb file in a loop", 2,
															read_test_200kb_file));
	add_test(unit, create_test("Test reading a 1000kb file in a loop", 2,
															read_test_1000kb_file));	
	run_unit(unit, NULL, true);
}

