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
#include <stdarg.h>

int	ft_eval_format(va_list arg, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(arg, int));
	if (specifier == 's')
		count += ft_print_string(va_arg(arg, char *));
	if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit(va_arg(arg, int), 10);
	// if (specifier == 'p')
	// 	count += ft_print_pointer(va_arg(arg, unsigned int));
	if (specifier == 'u')
		count += ft_print_digit((unsigned int)va_arg(arg, unsigned int), 10);
	if (specifier == 'X')
		count += ft_print_digit((unsigned int)va_arg(arg, unsigned int), 16);
	if (specifier == 'x')
		count += ft_print_digit((unsigned int)va_arg(arg, unsigned int), 16);
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
	// if (format[0] == 0)
	// {
	// 	error();
	// 	return (0);
	// }
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

#include <stdio.h>
int	main()
{
	int	count;

    // /*Check string*/
	// count = ft_printf("Je suis un %s\n", "poulet");
	// ft_printf("%d\n", count);
	// count = printf("Je suis un %s\n", "poulet");
	// printf("%d\n", count);

    // /*Check pour 'd' et 'i'*/
    // count = ft_printf("Je suis un %d\n", 2147483647);
	// ft_printf("%d\n", count);
	// count = printf("Je suis un %d\n", 2147483647);
	// printf("%d\n", count);

    // /*check for unsigned decimal*/
    // count = ft_printf("Je suis un %u\n", 65535);
	// ft_printf("%d\n", count);
	// count = printf("Je suis un %u\n", 65535);
	// printf("%d\n", count);
    
    /*Check unsigned hexa*/
    count = ft_printf("Le resultat est %X", 2147483647);
    ft_printf("%d", count);
    
	return (0);
}
