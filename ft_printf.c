/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofaure <thofaure@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:30:43 by thofaure          #+#    #+#             */
/*   Updated: 2024/11/26 10:17:29 by thofaure         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_diu(const char *p, size_t count, va_list args)
{
	char	*string;

	string = NULL;
	if (*p == 'd' || *p == 'i')
	{
		string = ft_itoa(va_arg(args, int));
		if (string == NULL)
			return (0);
		count += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else if (*p == 'u')
	{
		string = ft_itoa_u(va_arg(args, unsigned int));
		if (string == NULL)
			return (0);
		count += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else
		count = ft_print_x(p, count, args);
	return (count);
}

static int	ft_print_cs(const char *p, size_t count, va_list args)
{
	char	*string;

	string = NULL;
	if (*p == '%')
	{
		count++;
		ft_putchar_fd(*p, 1);
	}
	else if (*p == 'c')
	{
		count++;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (*p == 's')
	{
		string = ft_strdup(va_arg(args, char *));
		if (string == NULL)
			return (0);
		count += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else
		count = ft_print_diu(p, count, args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*p;
	size_t		count;

	va_start(args, format);
	p = format;
	count = 0;
	while (*p)
	{
		if (*p == '%' && p + 1)
		{
			p++;
			count = ft_print_cs(p, count, args);
			if (p + 1)
				p++;
		}
		else
		{
			ft_putchar_fd(*p, 1);
			count++;
			p++;
		}
	}
	va_end(args);
	return (count);
}
