/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:03:58 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/01 13:24:54 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_io.h"
#include <stdio.h>
#include <unistd.h>
#include "f_io.h"
#include "f_string.h"
#include "f_print.h"
#include "f_memory.h"


int		main(void)
{
	char buf[500];

	while (1)
	{
		fprintf(stderr, "%ld\n", f_readf(buf, STDIN, 20));
		f_print_err(buf);
		f_print_str("8 1\n");
		f_bzero(buf, 500);
	}

}

