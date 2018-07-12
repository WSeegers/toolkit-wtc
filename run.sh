#!/bin/sh

make &&\
gcc test.c libftprintf.a -I ./include &&\
./a.out | cat -e
