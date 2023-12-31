#include "main.h"

/**
 * convert - cvrt nums & base to str
 * @num: input numb
 * @base: input base
 * @lowercase: flag to lowercase hexa if needed
 * Return: str
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
