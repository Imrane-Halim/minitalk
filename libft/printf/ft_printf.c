/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:09:07 by ihalim            #+#    #+#             */
/*   Updated: 2024/11/14 11:41:56 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(const char s, va_list args)
{
	if (s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (s == 'x' || s == 'X')
		return (ft_puthex(va_arg(args, unsigned int), s));
	else if (s == '%')
		return (ft_putchar('%'));
	return (ft_putchar(s));
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;

	if (!string || write(1, 0, 0) == -1)
		return (-1);
	count = 0;
	va_start(args, string);
	while (*string != '\0')
	{
		if (*string == '%')
		{
			string++;
			count += ft_print_format(*string, args);
		}
		else
			count += write(1, string, 1);
		string++;
	}
	va_end(args);
	return (count);
}
