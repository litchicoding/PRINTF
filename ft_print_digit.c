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

int ft_nb_size(long int nb, int base)
{
	int i = 0;
	
	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0 && base == 10)
		i++;
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
	int 	j;
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

char	*ft_convert_itoa(char *buffer, long nb, int base, int original)
{
	int		temp;
	int		i;

	temp = 0;
	i = 0;
	while (nb != 0)
	{
		temp = nb % base;
		if (temp > 9)
			buffer[i++] = (temp - 10) + 'A';
		else
			buffer[i++] = temp + '0';
		nb /= base;
	}
	if (original < 0 && base == 10)
		buffer[i++] = '-';
	return (buffer);
}

char	*ft_itoa_base(int n, int base)
{
	char	*buffer;
	int		size;
	long	nb;
	
	if (base < 2 || base > 32)
		return (NULL);
	nb = n;
	size = ft_nb_size(nb, base);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	if (nb == 0)
		buffer[0] = '0';
	if (nb < 0)
		nb = -nb;
	buffer = ft_convert_itoa(buffer, nb, base, n);
	return (ft_final_string(buffer, size));
}

int	ft_print_digit(int nb, int base)
{
	int	count;
	char *new;

	count = 0;
	new = ft_itoa_base(nb, base);
	count += ft_print_string(new);
	free(new);
	return (count);
}