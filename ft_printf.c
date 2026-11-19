/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/18 09:28:53 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(va_list *ap, char conv)
{
	int	len;

	len = 0;
	if (conv == 'c')
		len = printchar(va_arg(*ap, int));
	if (conv == 's')
		len = printstr(va_arg(*ap, char *));
	if (conv == 'p')
		len = printptr(va_arg(*ap, void *));
	if (conv == 'd' || conv == 'i')
		len = printnum(va_arg(*ap, int));
	if (conv == 'u')
		len = printbase(va_arg(*ap, unsigned int), "0123456789");
	if (conv == 'x')
		len = printbase(va_arg(*ap, unsigned int), "0123456789abcdef");
	if (conv == 'X')
		len = printbase(va_arg(*ap, unsigned int), "0123456789ABCDEF");
	if (conv == '%')
		len = printchar('%');
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total;

	va_start(ap, fmt);
	total = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt++;
			total += dispatch(&ap, *fmt);
		}
		else if (*fmt != '%')
			total += printchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (total);
}
