/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ntoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:22:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/07 04:17:47 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
    wchar_t *s;
    s = (wchar_t *) malloc(sizeof(wchar_t) * 2);
    s[0] = 0xC539;
    s[1] = 0;

    setlocale(LC_ALL, "");

    if (printf("%ls\n", s) < 0) {
        perror("printf");
    }

    free(s);
    return (0);
}
