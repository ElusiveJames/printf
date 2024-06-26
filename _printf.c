#include "main.h"
/**
* _printf - Entry point
* @format: format
* Return: number of character printed
*/
int _printf(const char *format, ...)
{
	char *f_str = NULL;
	int f_int = 0;
	va_list args;
	int number;
	char buffer[100] = {0};

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0')
			return (-1);
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if (*format == 'c')
				f_int += _putchar(va_arg(args, int));
			else if (*format == 'd' || *format == 'i')
			{
				number = va_arg(args, int);
				if (number != 0)
				{
					snprintf(buffer, 100, "%d", number);
					f_int += write(1, buffer, strlen(buffer));
				}
				else
					f_int += write(1, "(null)", strlen("(null)"));
			}
			else if (*format == 's')
			{
				f_str = va_arg(args, char *);
				if (f_str == NULL)
					f_str = "(null)";
				f_int += write(1, f_str, strlen(f_str));
			}
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
