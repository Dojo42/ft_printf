/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofaure <thofaure@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:29:45 by thofaure          #+#    #+#             */
/*   Updated: 2024/11/26 10:33:15 by thofaure         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lennb_hexa_p(unsigned long int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*ft_itoa_hexa_p(unsigned long int n)
{
	char			*str;
	char			*hex;
	int				size;

	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (NULL);
	}
	hex = "0123456789abcdef";
	size = (ft_lennb_hexa_p(n));
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, size + 1);
	str[size--] = '\0';
	while (n >= 16)
	{
		str[size] = hex[(n % 16)];
		n /= 16;
		size--;
	}
	str[size] = hex[n];
	return (str);
}

static int	ft_print_p(const char *p, size_t count, va_list args)
{
	char		*string;

	string = NULL;
	if (*p == 'p')
	{
		count += 2;
		write (1, "0x", 2);
		string = ft_itoa_hexa_p(va_arg(args, unsigned long int));
		if (string == NULL)
			return (0);
		count += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
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
