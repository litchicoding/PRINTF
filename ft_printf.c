/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvallee <luvallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:07:40 by luvallee          #+#    #+#             */
/*   Updated: 2023/12/04 19:20:24 by luvallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format(va_list arg, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printf_char(va_arg(arg, int));
	if (specifier == 's')
		count += ft_printf_string(va_arg(arg, char *));
	if (specifier == 'p')
		count += ft_printf_adress((unsigned long)va_arg(arg, void *));
	if (specifier == 'd' || specifier == 'i')
		count += ft_printf_digit(va_arg(arg, int), 10, 'd');
	if (specifier == 'u')
		count += ft_printf_digit(va_arg(arg, unsigned int), 10, 'u');
	if (specifier == 'X')
		count += ft_printf_digit(va_arg(arg, unsigned int), 16, 'X');
	if (specifier == 'x')
		count += ft_printf_digit(va_arg(arg, unsigned int), 16, 'x');
	if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		return_value;
	va_list	arg;

	return_value = 0;
	va_start(arg, format);
	if (format[0] == 0)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%')
			return_value += ft_eval_format(arg, *(++format));
		else
			return_value += write(1, format, 1);
		++format;
	}
	va_end(arg);
	return (return_value);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	count;

// 	count = 0;
// printf("[remake] :\n");
// count = ft_printf("%X\n", -1);
// printf("%d\n", count);
// printf("[original] :\n");
// count = printf("%X\n", -1);
// printf("%d\n", count);
// printf("[remake] :\n");
// count = ft_printf("%d\n", -10);
// printf("%d\n", count);
// printf("[original] :\n");
// count = printf("%d\n", -10);
// printf("%d\n", count);
// printf("[remake] :\n");
// count = ft_printf(" NULL %s NULL \n", (char *)NULL);
// printf("%d\n", count);
// printf("[original] :\n");
// count = printf(" NULL %s NULL \n", (char *)NULL);
// // printf("%d\n", count);
// printf("[remake] :\n");
// count = ft_printf("% jghf", "");
// printf("\n%d\n", count);
// printf("[original] :\n");
// count = printf("% jgf", "");
// printf("\n%d\n", count);
// 	return (0);
// }
