#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define UNUSED(x)

int _printf(const char *format, ...);
int  printNumber(int num, int sum);
void print_string(const char *string, int *prt);
void print(int *prt, const char *format);
void init_buffer(char *buff_size[]);
int convert_bin(va_list v_args, char buffer, int flag, int wide, int lng);
const char *check_format(const char *format, int *prt, va_list is_args);
char *_strchr(char *s, char c);
int printUnsignedNumber(unsigned int num, int sum);
int _putchar(char c)

#endif /* MAIN_H */
