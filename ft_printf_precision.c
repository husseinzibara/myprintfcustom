/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 13:28:22 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/* String precision = maximum number of characters printed. */
char	*trim_str(char *s, int prec)
{
	char	*new;

	if (prec < 0 || (size_t)prec >= ft_strlen(s))
		return (s);
	new = ft_substr(s, 0, prec);
	if (!new)
		return (s);
	free(s);
	return (new);
}

/*
** Integer precision = minimum number of DIGITS (sign not counted).
** Value 0 with precision 0 prints no digits at all.
** Once a precision is given, the '0' flag is ignored.
*/
void	apply_prec(char **s, t_spec *spec, int is_zero)
{
	char	*tmp;

	if (spec->prec < 0)
		return ;
	if (spec->prec == 0 && is_zero)
	{
		tmp = *s;
		*s = ft_strdup("");
		free(tmp);
	}
	else
		zero_pad(s, spec->prec + ((*s)[0] == '-'));
	filter_mods(spec->mods, "-+ #");
}
