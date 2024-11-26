/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofaure <thofaure@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:18:29 by thofaure          #+#    #+#             */
/*   Updated: 2024/11/26 09:42:07 by thofaure         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lennb(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;
	long int	num;

	num = n;
	size = (ft_lennb(n));
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, size + 1);
	str[size--] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num >= 10)
	{
		str[size] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	str[size] = num + '0';
	return (str);
}

static int	ft_lennb_u(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	int				size;
	unsigned int	num;

	num = n;
	size = (ft_lennb_u(n));
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, size + 1);
	str[size--] = '\0';
	while (num >= 10)
	{
		str[size] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	str[size] = num + '0';
	return (str);
}
