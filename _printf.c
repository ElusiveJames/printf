#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
#include <unistd.h>

/**
* _printf - function that prints a formatted string
* @format: format string
* Return: number of characters printed
*/

int _printf(const char *format, ...)
{
	char *f_str = NULL;
	int f_int = 0;
	char f_char;
	char special;
	
	va_list list;

	va_start(list, format);

	if (format == NULL)
		return (-1);

	while  (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					f_str = va_arg(list, char *);
					f_int += write(1, f_str, strlen(f_str));
					write(1, "\0",1);
					format++;
					break;
				case 'c':
					f_char = va_arg(list, int);
					f_int += write(1, &f_char, 1);
					format++;
					break;
				case '%':
					special = '%';
					f_int += write(1, &special, 1);
					format++;
					break;
				default:
					return (-1);
			}

		}
		else
		{
			f_int += write(1, format, 1);
			format++;
		}
	}
	va_end(list);
	return (f_int);
}
