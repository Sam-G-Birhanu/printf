#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
void printNumber(int num);
void init_buffer(char buff_size[]);

#endif /* MAIN_H */
