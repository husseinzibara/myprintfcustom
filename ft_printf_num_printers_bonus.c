/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_printers_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/18 09:28:18 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	printptr(void *ptr, t_spec *spec, t_flag *flags)
{
	int		len;
	char	*s;

	if (!ptr)
		s = ft_strdup("(nil)");
	else
		s = ft_itobase((unsigned long)ptr, "0123456789abcdef");
	if (!s)
		return (0);
	if (ptr)
		hex_memory(&s, 0);
	if (ptr)
		filter_mods(spec->mods, "-0");
	else
		filter_mods(spec->mods, "-");
	len = apply_flags(&s, spec->width, spec->mods, flags);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

int	printnum(int num, t_spec *spec, t_flag *flags)
{
	int		len;
	char	*s;

	s = ft_itoa(num);
	if (!s)
		return (0);
	filter_mods(spec->mods, "-+ 0");
	apply_prec(&s, spec, num == 0);
	len = apply_flags(&s, spec->width, spec->mods, flags);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

int	printuint(unsigned int num, t_spec *spec, t_flag *flags)
{
	int		len;
	char	*s;

	s = ft_itobase(num, "0123456789");
	if (!s)
		return (0);
	filter_mods(spec->mods, "-0");
	apply_prec(&s, spec, num == 0);
	len = apply_flags(&s, spec->width, spec->mods, flags);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
