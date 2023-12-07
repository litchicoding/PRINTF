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
		// error();
		return (0);
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
// 	int				count;
// 	unsigned long	i;
// 	unsigned long	*pointer;
// 	unsigned long	b;

// 	// count = 0;
// 	// 	// 	// 	// ft_printf("[REMAKE] : ");
// 	// 	// 	// 	// count = ft_printf(" %X ", 9223372036854775807LL);
// 	// 	// 	// 	// printf("\ncount : %d\n", count);
// 	// 	// 	// 	// ft_printf("[ORIGIN] : ");
// 	// 	// 	// 	// count = printf(" %X ", 9223372036854775807LL);
// 	// 	// 	// 	// printf("\ncount : %d\n", count);
// 	i = 0;
// 	b = 0;
// 	pointer = &i;
// 	ft_printf("[REMAKE] : ");
// 	count = ft_printf(" %p  %p", (void *)i, (void *)b);
// 	printf("\ncount : %d\n", count);
// 	ft_printf("[ORIGIN] : ");
// 	count = printf(" %p  %p", (void *)i, (void *)b);
// 	printf("\ncount : %d\n", count);
// 	return (0);
// }
