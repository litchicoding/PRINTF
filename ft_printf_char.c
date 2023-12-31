/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvallee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:54:05 by luvallee          #+#    #+#             */
/*   Updated: 2023/12/05 10:54:08 by luvallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character == '\0')
		return (write(1, "\0", 1));
	return (write(1, &character, 1));
}
