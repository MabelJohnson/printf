#include "main.h"
/**
 * get_print_func - gets func based on specifier
 * @spc: specifier passed
 *
 * Return: pointer to the func
*/
int (*get_print_func(char spc))(va_list, char *, int *)
{
	pnt pnt_f[] = {
	{'c', pnt_char},
	{'s', pnt_string},
	{'%', pnt_percentage},
	{'d', pnt_number},
	{'i', pnt_number},
	{'\0', NULL}
	};
	int i;

	i = 0;
	while (pnt_f[i].spc != '\0')
	{
		if (pnt_f[i].spc == spc)
			return (pnt_f[i].f);
		i++;
	}
	return (NULL);
}
