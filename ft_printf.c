/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:03:51 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/14 16:18:04 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
void initiateflags(t_flag **flag)
{
	(*flag)[0].c = '-';
	(*flag)[0].f = left_justify;
	(*flag)[1].c = '+';
	(*flag)[1].f = force_sign;
	(*flag)[2].c = ' ';
	(*flag)[2].f = sign_pad;
	(*flag)[3].c = '#';
	(*flag)[3].f = mem_float;
	(*flag)[4].c = '0';
	(*flag)[4].f = zero_pad;
	(*flag)[5].c = '.';
	(*flag)[5].f = precision_int;
}
int dispatch(va_list *ap, char **fmt, t_flag *flags, int *totalwidth)
{
	int		minwidth;
	char	*output;
	char	*mods;

	minwidth = 0;
	*fmt ++;
	while(ft_strchr((const char *)"-+ #0.",**fmt) && strlen(mods) < 5)
		mods++ = *fmt++;
	if(**fmt == 'i' || **fmt == 'd')
		printnum(va_arg(*ap, int *), &output, mods, &totalwidth, &flags);
	if(**fmt == 's')
		printstr(va_arg(*ap, char *), &output, mods, &totalwidth, &flags);
	if(**fmt == 'c')
		printchar(va_arg(*ap, char), &output, mods, &totalwidth, &flags);
	if(**fmt == 'p')
		printptr(va_arg(*ap, void *), &output, mods, &totalwidth, &flags);
	if(**fmt == 'u')
		printuint(va_arg(*ap, unsigned int *), &output, mods, &totalwidth, &flags);
	if(**fmt == 'x')
		printhex(va_arg(*ap, int *), &output, mods, &totalwidth, &flags	);
	if(**fmt == 'X')
		printHEX(va_arg(*ap, int *), &output, mods, &totalwidth, &flags);
	if(**fmt == '%')
		printchar('%', &output, mods, &totalwidth, &flags);
	return (totalwidth);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	char	c;
	t_flag	*flags;
	int 	totalwidth;
	
	va_start(ap, fmt);
	initiateflags(&flags);
	while (*fmt)
	{
		if (*fmt == '%')
			totalwidth = dispatch(ap, &fmt, flags, &totalwidth);
		else
		{
			write(1, fmt, 1);
			totalwidth++;
		}
		fmt++;
	}
	va_end(ap);
	return (totalwidth);
}
