/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/18 09:30:54 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(int c)
{
	char	ch;

	ch = (char)c;
	write(1, &ch, 1);
	return (1);
}

int	printstr(char *s)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	printnum(int num)
{
	int		len;
	char	*s;

	s = ft_itoa(num);
	if (!s)
		return (0);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

int	printbase(unsigned long num, char *base)
{
	int		len;
	char	*s;

	s = ft_itobase(num, base);
	if (!s)
		return (0);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

int	printptr(void *ptr)
{
	if (!ptr)
		return (printstr("(nil)"));
	ft_putstr_fd("0x", 1);
	return (2 + printbase((unsigned long)ptr, "0123456789abcdef"));
}
