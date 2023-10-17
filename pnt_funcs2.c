#include "main.h"
/**
 * _putchar - writes the character
 * @c: char to print
 *
 * Return: 1 (Success), -1 (error)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * pnt_number - prints out an integer
 * @list: list to take info from
 * @buffer: buffer to print
 * @pointer: where to start printing
 *
 * Return: num of chars printed
*/
int pnt_number(va_list list, char *buffer, int *pointer)
{
	int x = 10, n = va_arg(list, int), c = 2;
	unsigned int m, g;

	m = ABS(n);
	VOIDED(buffer);
	VOIDED(pointer);
	for (c = 2; (m / x) >= 10; c++)
		x = x * 10;
	if (n < 0)
	{
		_putchar('-');
		c++;
		if (n > -10)
		{
			_putchar(-n + '0');
		} else
		{
			while (x != 0)
			{
				g = -n;
				g = (g / x) % 10;
				x = x / 10;
				_putchar(g + '0');
			}
		}
	} else if (n < 10)
	{
		_putchar(n + '0');
	} else
	{
		while (x != 0)
		{
			g = n;
			g = (g / x) % 10;
			x = x / 10;
			_putchar(g + '0');
		}
	}
	return (c);
}
