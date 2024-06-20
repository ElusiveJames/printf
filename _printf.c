#include "main.h"
/**
* _printf - Entry point
* @format: format
* Return: number of character printed
*/
int _printf(const char *format, ...)
{
	int f_int = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
				f_int += _putchar(va_arg(args, int));
			else if (*format == NULL)
				return (-1);
			else if (*format == 's')
				f_int += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
			else if (*format == '%')
				f_int += _putchar('%');
			else
			{
				f_int += _putchar('%');
				f_int += _putchar(*format);
			}
			format++;

		}
		else
		{
			f_int += _putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (f_int);
}
