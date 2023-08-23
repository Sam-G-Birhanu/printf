#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
void printNumber(int num);
void init_buffer(char *buff_size[]);
int convert_bin(va_list v_args, char *buffer[],int flag, int wide, int lng);

#endif /* MAIN_H */
