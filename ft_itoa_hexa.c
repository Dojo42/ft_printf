/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofaure <thofaure@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:35:14 by thofaure          #+#    #+#             */
/*   Updated: 2024/11/26 10:34:08 by thofaure         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lennb_hexa(unsigned int n)
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

char	*ft_itoa_hexa(unsigned int n)
{
	char			*str;
	int				size;
	unsigned int	num;

	num = n;
	size = (ft_lennb_hexa(n));
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, size + 1);
	str[size--] = '\0';
	while (num >= 16)
	{
		if ((num % 16) > 9)
			str[size] = (num % 16) + 87;
		else
			str[size] = (num % 16) + '0';
		num /= 16;
		size--;
	}
	if (num > 9)
		str[size] = (num % 16) + 87;
	else
		str[size] = (num % 16) + '0';
	return (str);
}

char	*ft_itoa_hexa_up(unsigned int n)
{
	char			*str;
	int				size;
	unsigned int	num;

	num = n;
	size = (ft_lennb_hexa(n));
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, 0, size + 1);
	str[size--] = '\0';
	while (num >= 16)
	{
		if ((num % 16) > 9)
			str[size] = (num % 16) + 55;
		else
			str[size] = (num % 16) + '0';
		num /= 16;
		size--;
	}
	if (num > 9)
		str[size] = (num % 16) + 87;
	else
		str[size] = (num % 16) + '0';
	return (str);
}
