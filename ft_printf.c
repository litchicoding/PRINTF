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
	// if (specifier == 'p')
	// 	count += ft_print_pointer(va_arg(arg, unsigned int));
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

#include <stdio.h>

int	main(void)
{
	int	count;

	count = 0;
	// 	// 	// 	// 	// 	/*Check STRING*/
	// 	// 	// 	// 	// 	ft_printf("Check pour 's' = \n");
	// 	// 	// 	// 	// 	ft_printf("[re] : ");
	// 	// 	// 	// 	// 	count = ft_printf(" NULL %s NULL ", NULL);
	// 	// 	// 	// 	// 	printf("\n[%d]\n", count);
	// 	// 	// 	// 	// 	ft_printf("[o] : ");
	// 	// 	// 	// 	// 	count = printf(" NULL %s NULL ", NULL);
	// 	// 	// 	// 	// 	printf("\n[%d]\n", count);
	// 	// 	// 	// printf("\n##############################");
	// 	// 	// 	// /*Check pour 'd' et 'i'*/
	// 	// 	// 	// ft_printf("Check pour 'd' et 'i' = \n");
	// 	// 	// 	// ft_printf("[re] : ");
	// 	// 	// 	// count = ft_printf("Je suis un %d", 2147483647);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// ft_printf("[o] : ");
	// 	// 	// 	// count = printf("Je suis un %d", 2147483647);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// ft_printf("[re] : ");
	// 	// 	// 	// count = ft_printf("Je suis un %i", -2147483647);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// ft_printf("[o] : ");
	// 	// 	// 	// count = printf("Je suis un %i", -2147483647);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// printf("\n##############################");
	// 	// 	// 	// /*Check for unsigned decimal*/
	// 	// 	// 	// ft_printf("Check pour 'u' = \n");
	// 	// 	// 	// ft_printf("[re] : ");
	// 	// 	// 	// count = ft_printf("Je suis un %u", 65535);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// ft_printf("[o] : ");
	// 	// 	// 	// count = printf("Je suis un %u", 65535);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// ft_printf("[re] : ");
	// 	// 	// 	// count = ft_printf("Je suis un %u", -65535);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// ft_printf("[o] : ");
	// 	// 	// 	// count = printf("Je suis un %u", -65535);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// printf("\n##############################");
	// 	// 	// 	// // /*Check unsigned hexa*/
	// 	// 	// 	// ft_printf("Check pour 'X' = \n");
	// 	// 	// 	// ft_printf("[re] : ");
	// 	// 	// 	// count = ft_printf("Le resultat est %X", 2147483647);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// ft_printf("[o] : ");
	// 	// 	// 	// count = printf("Le resultat est %X", 2147483647);
	// 	// 	// 	// printf("\n[%d]\n", count);
	// 	// 	// 	// ft_printf("[re] : ");
	// 	// 	// 	// count = ft_printf("Le resultat est %X", -11184810);
	// 	// 	// 	ft_printf("[re] : ");
	// 	// 	// 	count = ft_printf("Le resultat est %x", -2147483647);
	// 	// 	// 	printf("\n[%d]\n", count);
	// 	// 	// 	ft_printf("[o] : ");
	// 	// 	// 	count = printf("Le resultat est %x", -2147483647);
	// 	// 	// 	printf("\n[%d]\n", count);
	// 	// 	// 	// 	// ft_printf("%i", ft_printf(" NULL %s NULL ", NULL));
	// 	// 	// 	// 	// printf("%i", printf(" NULL %s NULL", NULL));
	ft_printf("[REMAKE] : ");
	count = ft_printf(" %X ", 9223372036854775807LL);
	printf("\ncount : %d\n", count);
	ft_printf("[ORIGIN] : ");
	count = printf(" %X ", 9223372036854775807LL);
	printf("\ncount : %d\n", count);
	return (0);
}
