#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>


int _printf(const char *format, ...);
void print_char(char c, int *count);
void print_string(const char *str, int *count);

#endif
