/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofaure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:30:43 by thofaure          #+#    #+#             */
/*   Updated: 2024/11/22 10:49:53 by thofaure         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_print_cs(const char *p, size_t count, va_list args)
{

	if (*p == '%')
	{
		count++;
		ft_putchar_fd(*p, 1);
	}
	else if (*p == 'c')
	{
		count++;
		ft_putchar_fd(va_arg(args, char), 1);
	}
	else if (*p == 's')
	{
		char	*string;

		string = ft_strdup(va_args(args, char *));
		count += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
	}
	else
		count += //nouvelle fonction;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*p;
	size_t		count;

	va_start(args, format);
	count == 0;
	while (*p)
	{
		if (*p == '%' && p + 1)
		{
			p++;
			//count += envoie fonction de trie
			if (p + 1)
				p++;
		}
		else
		{
			ft_putchar_fd(*p, 1);
			count ++;
			p++;
		}
	}
	va_end(args);
	return(count);
}
