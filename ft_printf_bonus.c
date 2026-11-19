/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/18 21:31:22 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	get_mods(char **fmt, t_spec *spec)
{
	int	i;

	i = 0;
	spec->width = 0;
	spec->prec = -1;
	(*fmt)++;
	while (**fmt && ft_strchr("-+ #0", **fmt))
	{
		if (i < 7)
		{
			spec->mods[i] = **fmt;
			i++;
		}
		(*fmt)++;
	}
	spec->mods[i] = '\0';
}

static void	get_width(va_list *ap, char **fmt, t_spec *spec)
{
	int	len;

	if (**fmt == '*')
	{
		spec->width = va_arg(*ap, int);
		(*fmt)++;
		if (spec->width < 0)
		{
			len = ft_strlen(spec->mods);
			spec->mods[len] = '-';
			spec->mods[len + 1] = '\0';
			spec->width = -spec->width;
		}
	}
	else if (ft_isdigit(**fmt))
	{
		spec->width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}

static void	get_prec(va_list *ap, char **fmt, t_spec *spec)
{
	if (**fmt != '.')
		return ;
	(*fmt)++;
	spec->prec = 0;
	if (**fmt == '*')
	{
		spec->prec = va_arg(*ap, int);
		(*fmt)++;
		if (spec->prec < 0)
			spec->prec = -1;
	}
	else if (ft_isdigit(**fmt))
	{
		spec->prec = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}

static int	dispatch(va_list *ap, char **fmt, t_flag *flags)
{
	t_spec	spec;
	int		len;

	len = 0;
	get_mods(fmt, &spec);
	get_width(ap, fmt, &spec);
	get_prec(ap, fmt, &spec);
	if (**fmt == 'i' || **fmt == 'd')
		len = printnum(va_arg(*ap, int), &spec, flags);
	if (**fmt == 's')
		len = printstr(va_arg(*ap, char *), &spec, flags);
	if (**fmt == 'c')
		len = printchar(va_arg(*ap, int), &spec, flags);
	if (**fmt == 'p')
		len = printptr(va_arg(*ap, void *), &spec, flags);
	if (**fmt == 'u')
		len = printuint(va_arg(*ap, unsigned int), &spec, flags);
	if (**fmt == 'x')
		len = printhex(va_arg(*ap, unsigned int), &spec, flags);
	if (**fmt == 'X')
		len = printhex_upper(va_arg(*ap, unsigned int), &spec, flags);
	if (**fmt == '%')
		len = printchar('%', &spec, flags);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_flag	flags[6];
	int		totalwidth;

	va_start(ap, fmt);
	initiateflags(flags);
	totalwidth = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			totalwidth += dispatch(&ap, (char **)&fmt, flags);
			if (!*fmt)
				break ;
		}
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
