/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:20:57 by ihalim            #+#    #+#             */
/*   Updated: 2024/11/10 17:44:54 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int				cout;
	unsigned long	addr;

	cout = 0;
	addr = (unsigned long)p;
	if (addr == 0)
		return (ft_putstr("0x0"));
	cout += ft_putstr("0x");
	cout += ft_puthex(addr, 'x');
	return (cout);
}
