/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:09:35 by ihalim            #+#    #+#             */
/*   Updated: 2024/11/07 12:30:55 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_print_format(const char s, va_list args);

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putptr(void *p);
int	ft_putnbr(int n);
int	ft_puthex(unsigned long n, int isupper);
int	ft_unsigned(unsigned int n);

#endif
