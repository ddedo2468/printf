#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character
 * @c: char for printing
 * Return: 1 success.
 * if error, return -1
 * Description: _putchar uses a local buffer of 1024.
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - print str to stdout
 * @str: pointer to str for printing
 * Return: num of chars written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
/**
 * print_percent - print percent sign
 * @l: va_list arguments from _printf
 * @f: ptr to srct flags that turned the flags on
 * Return: num of character printed
 */
int print_percent(va_list l, fl_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}
/**
 * print_string - loop through str and print it
 * @l: va_list arguments from _printf
 * @f: ptr to the srct flags
 * Return: num of character printed
 */
int print_string(va_list l, fl_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_char - prints a char
 * @l: va_list arguments from _printf
 * @f: ptr to the srct flags
 * if a flag is passed to _printf
 * Return: num of character printed
 */
int print_char(va_list l, fl_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
