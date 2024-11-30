/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:09:13 by ihalim            #+#    #+#             */
/*   Updated: 2024/11/08 22:20:09 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, int isupper)
{
	int		count;
	char	*base;

	if (isupper == 'x')
		base = "0123456789abcdef";
	else if (isupper == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
		count += ft_putchar((int)base[n]);
	else
	{
		count += ft_puthex(n / 16, isupper);
		count += ft_puthex(n % 16, isupper);
	}
	return (count);
}
