/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/18 08:54:07 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*trim_str(char *s, int prec)
{
	char	*trimmed;

	if (prec < 0 || (size_t)prec >= ft_strlen(s))
		return (s);
	trimmed = ft_substr(s, 0, prec);
	if (!trimmed)
		return (s);
	free(s);
	return (trimmed);
}

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
