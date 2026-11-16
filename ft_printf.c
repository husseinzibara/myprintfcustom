/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:03:51 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 16:25:46 by hzibara          ###   ########.fr       */
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
	(*flag)[2].f = signpad;
	(*flag)[3].c = '#';
	(*flag)[3].f = hex_memory;
	(*flag)[4].c = '0';
	(*flag)[4].f = zero_pad;
}

size_t get_mods(char **fmt, int *minwidth, char **mods)
{
	int	i;

	i = 0;
		(*fmt)++;
	while(**fmt && ft_strchr((const char *)"-+ #0.",**fmt) && i < 4)
		mods[i++] = (*(*fmt)++);
	mods[i] = 0;
	if (ft_isdigit(**fmt))
		minwidth = atoi(*fmt);
	
}
int dispatch(va_list *ap, char **fmt, t_flag *flags, int *totalwidth)
{
	int		width;
	char	mods[5];

	width = 0;
	width = get_mods(fmt, &width, &mods);
	if(**fmt == 'i' || **fmt == 'd')
		printnum(va_arg(*ap, int), mods, &flags);
	if(**fmt == 's')
		printstr(va_arg(*ap, char *), &width, mods, &flags);
	if(**fmt == 'c')
		printchar(va_arg(*ap, char), &width, mods, &flags);
	if(**fmt == 'p')
		printptr(va_arg(*ap, void *), &width, mods, &flags);
	if(**fmt == 'u')
		printuint(va_arg(*ap, unsigned int), &width, mods, &flags);
	if(**fmt == 'x')
		printhex(va_arg(*ap, unsigned int), &width, mods, &flags);
	if(**fmt == 'X')
		printHEX(va_arg(*ap, int *), &width, mods, &flags);
	if(**fmt == '%')
		printchar('%', &width, mods, &flags);
	return (width);
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
