#include "main.h"
/**
 * _printf - prints a format
 * @format: format for the written text
 *
 * Return: number of chars printed
*/
int _printf(const char *format, ...)
{
	int nchar = 0, ifspace = 0, i, pointer = 0;
	char buffer[BSIZE];
	int (*pnt_func)(va_list, char *, int *);
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[pointer++] = format[i];
			if (pointer == BSIZE)
				pnt_buffer(buffer, &pointer);
			nchar++;
		} else
		{
			pnt_buffer(buffer, &pointer);
			for (; format[i + 1] && format[i + 1] == ' '; i++)
				ifspace = 1;
			pnt_func = get_print_func(format[i + 1]);
			if (pnt_func != NULL)
			{
				nchar += pnt_func(list, buffer, &pointer);
				i++;
				pnt_func = NULL;
				continue;
			}
			if (format[i + 1] == '\0')
				return (-1);
			write(1, "%%", 1);
			nchar += (ifspace + 1);
			ifspace -= (ifspace == 1 ? write(1, " ", 1) : 0);
		}
	}
	pnt_buffer(buffer, &pointer);
	va_end(list);
	return (nchar);
}
