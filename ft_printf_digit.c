/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvallee <luvallee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:13:27 by luvallee          #+#    #+#             */
/*   Updated: 2023/12/04 19:16:19 by luvallee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nb_size(unsigned long long nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_final_string(char *buffer, int size)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = size - 1;
	while (i <= j)
	{
		temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
		i++;
		j--;
	}
	buffer[size] = '\0';
	return (buffer);
}

char	*ft_convert_itoa(char *buffer, unsigned long long nb, int base,
		char specifier)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	while (nb != 0)
	{
		temp = nb % base;
		if (temp > 9 && specifier == 'X')
			buffer[i++] = temp - 10 + 'A';
		else if (temp > 9 && specifier == 'x')
			buffer[i++] = temp - 10 + 'a';
		else
			buffer[i++] = temp + '0';
		nb /= base;
	}
	return (buffer);
}

char	*ft_itoa_base(unsigned long long nb, int base, int neg, char specifier)
{
	char	*buffer;
	int		size;

	if (neg < 0 && specifier == 'd')
	{
		size = ft_nb_size(neg, base) + 1;
		nb = neg;
	}
	else
		size = ft_nb_size(nb, base);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	if (nb == 0)
		buffer[0] = '0';
	if (neg < 0 && specifier == 'd')
	{
		buffer[size - 1] = '-';
		nb = -nb;
	}
	buffer = ft_convert_itoa(buffer, nb, base, specifier);
	return (ft_final_string(buffer, size));
}

int	ft_printf_digit(long long nb, int base, char specifier)
{
	int		count;
	char	*new;

	count = 0;
	new = ft_itoa_base(nb, base, nb, specifier);
	count += ft_printf_string(new);
	free(new);
	return (count);
}
