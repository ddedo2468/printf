#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in the format string
 * @x: character that holds the flag specifier
 * @pf: pointer to the struct flags in which we turn the flags on
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char x, fl_t *pf)
{
	int i = 0;

	switch (x)
	{
		case '+':
			pf->plus = 1;
			i = 1;
			break;
		case ' ':
			pf->space = 1;
			i = 1;
			break;
		case '#':
			pf->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
