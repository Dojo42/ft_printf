/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofaure <thofaure@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 07:42:12 by thofaure          #+#    #+#             */
/*   Updated: 2024/11/26 09:50:45 by thofaure         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_x(const char *p, size_t count, va_list args);
void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa_hexa(unsigned int n);
char	*ft_itoa_hexa_up(unsigned int n);
size_t	ft_strlen(const char *s);

#endif
