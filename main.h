#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct fl
{
	int plus;
	int space;
	int hash;
} fl_t;

/**
 * struct Prhandle - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct Prhandle
{
	char c;
	int (*f)(va_list ap, fl_t *f);
} hpr;

/* print_nums */
int print_int(va_list l, fl_t *f);
void print_number(int n);
int print_unsigned(va_list l, fl_t *f);
int count_digit(int i);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, fl_t *);

/* get_flag */
int get_flag(char x, fl_t *pf);

/* print_alpha */
int print_string(va_list l, fl_t *f);
int print_char(va_list l, fl_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_percent */
int print_percent(va_list l, fl_t *f);

#endif
