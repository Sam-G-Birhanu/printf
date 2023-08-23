#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
void printNumber(int num);
void print_string(const char *string, int *prt);
void print(int *prt, const char *format);
void init_buffer(char *buff_size[]);

#endif /* MAIN_H */
