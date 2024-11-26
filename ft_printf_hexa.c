/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofaure <thofaure@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:29:45 by thofaure          #+#    #+#             */
/*   Updated: 2024/11/26 11:07:02 by thofaure         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hexa_p(unsigned long int n)
{
	size_t		size;
	size_t		i;
	char		buffer[42];
	char		*hex;

	hex = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	size = 2;
	write (1, "0x", 2);
	while (n)
	{
		buffer[i] = hex[n % 16];
		n /= 16;
		i++;
		size++;
	}
	while (i--)
		ft_putchar_fd(buffer[i], 1);
	return (size);
}

static int	ft_print_p(const char *p, size_t count, va_list args)
{
	if (*p == 'p')
		count += ft_putnbr_hexa_p(va_arg(args, unsigned long int));
	return (count);
}

int	ft_print_x(const char *p, size_t count, va_list args)
{
	char	*string;

	string = NULL;
	if (*p == 'x')
	{
		string = ft_itoa_hexa(va_arg(args, unsigned int));
		if (string == NULL)
			return (0);
		count += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else if (*p == 'X')
	{
		string = ft_itoa_hexa_up(va_arg(args, unsigned int));
		if (string == NULL)
			return (0);
		count += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else
		count = ft_print_p(p, count, args);
	return (count);
}
