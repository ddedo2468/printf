#include "main.h"

/**
 * _printf - clone printf implimintation
 * @format: format str contains the chrs and the specifiers
 * Return: lnth of the formatted str
 */

int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, fl_t *);
	const char *p;
	va_list arguments;
	fl_t flags = {0, 0, 0};

	register int i = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				i += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			i += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			i += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (i);
}
