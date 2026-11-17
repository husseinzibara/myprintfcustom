/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 13:28:22 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

/*
** The ORDER of this array is the order flags are applied, whatever order
** the user typed them in: prefix/sign first, then zero fill (which has to
** go AFTER the sign/prefix so it can pad around them), then '-' last.
*/
void	initiateflags(t_flag *flag)
{
	flag[0].c = '#';
	flag[0].f = hex_memory;
	flag[1].c = '+';
	flag[1].f = force_sign;
	flag[2].c = ' ';
	flag[2].f = signpad;
	flag[3].c = '0';
	flag[3].f = zero_pad;
	flag[4].c = '-';
	flag[4].f = left_justify;
	flag[5].c = '\0';
	flag[5].f = NULL;
}

/* Removes from mods every flag the current conversion ignores. */
void	filter_mods(char *mods, char *allowed)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (mods[i])
	{
		if (ft_strchr(allowed, mods[i]))
			mods[k++] = mods[i];
		i++;
	}
	mods[k] = '\0';
}

/* Default alignment (no '-'): pad with spaces on the LEFT. */
size_t	right_justify(char **s, size_t width)
{
	char	*pad;
	char	*tmp;
	size_t	len;

	len = ft_strlen(*s);
	if (len >= width)
		return (len);
	pad = ft_calloc(width - len + 1, sizeof(char));
	if (!pad)
		return (len);
	ft_memset(pad, ' ', width - len);
	tmp = *s;
	*s = ft_strjoin(pad, tmp);
	free(pad);
	free(tmp);
	return (ft_strlen(*s));
}

size_t	apply_flags(char **s, size_t width, char *mods, t_flag *flags)
{
	size_t	len;
	int		j;

	len = ft_strlen(*s);
	j = 0;
	while (flags[j].c != '\0')
	{
		if (ft_strchr(mods, flags[j].c)
			&& !(flags[j].c == '0' && ft_strchr(mods, '-')))
			len = flags[j].f(s, width);
		j++;
	}
	if (!ft_strchr(mods, '-'))
		len = right_justify(s, width);
	return (len);
}
