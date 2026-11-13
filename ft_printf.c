/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:03:51 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/13 11:59:25 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void precision_int(char **s, int *minwidth)
{
	
}

void modnum(int* num, char **output, char *mods)
{
	
}

void modchar(char *c , char **output, char *mods)
{
	
}

int dispatch(va_list *, char **fmt, t_flag *flags)
{
	int		minwidth;
	char	*output;
	char	*mods;

	minwidth = 0;
	if(**fmt == '%')
		*fmt ++;
	while(ft_strchr((const char *)"-+ #0.",**fmt))
		*mods++ = **fmt++
	if(**fmt == 'i' || **fmt == 'd')
		
}

ft_printf(const char *fmt, ...)
{
	va_list ap;
	char	c;
	t_flag	*flags;
	
	va_start(ap, fmt);
	initiateflags(&flags);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			while(flags++)
			{
				if(flags->c == (char **)&fmt)
					flags->f(dispatch(&ap,(char *)&fmt, flags));
			}
		}
		else
			write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
}