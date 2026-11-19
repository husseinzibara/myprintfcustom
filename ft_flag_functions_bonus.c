/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/18 09:30:30 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	left_justify(char **s, size_t width)
{
	char	*pad;
	char	*tmp;

	if (ft_strlen(*s) >= width)
		return (ft_strlen(*s));
	pad = ft_calloc(width - ft_strlen(*s) + 1, sizeof(char));
	if (!pad)
		return (ft_strlen(*s));
	ft_memset(pad, ' ', width - ft_strlen(*s));
	tmp = *s;
	*s = ft_strjoin(tmp, pad);
	free(pad);
	free(tmp);
	return (ft_strlen(*s));
}

size_t	force_sign(char **s, size_t width)
{
	char	*tmp;

	(void)width;
	if ((*s)[0] == '-' || (*s)[0] == '+')
		return (ft_strlen(*s));
	tmp = *s;
	*s = ft_strjoin("+", tmp);
	free(tmp);
	return (ft_strlen(*s));
}

size_t	signpad(char **s, size_t width)
{
	char	*tmp;

	(void)width;
	if ((*s)[0] == '-' || (*s)[0] == '+')
		return (ft_strlen(*s));
	tmp = *s;
	*s = ft_strjoin(" ", tmp);
	free(tmp);
	return (ft_strlen(*s));
}

size_t	hex_memory(char **s, size_t width)
{
	char	*tmp;

	(void)width;
	tmp = *s;
	*s = ft_strjoin("0x", tmp);
	free(tmp);
	return (ft_strlen(*s));
}

size_t	zero_pad(char **s, size_t width)
{
	size_t	len;
	size_t	skip;
	char	*padded;

	len = ft_strlen(*s);
	if (len >= width)
		return (len);
	skip = ((*s)[0] == '-' || (*s)[0] == '+' || (*s)[0] == ' ');
	if ((*s)[skip] == '0' && (*s)[skip + 1] == 'x')
		skip += 2;
	padded = malloc(width + 1);
	if (!padded)
		return (len);
	ft_memcpy(padded, *s, skip);
	ft_memset(padded + skip, '0', width - len);
	ft_strlcpy(padded + skip + (width - len), *s + skip, len - skip + 1);
	free(*s);
	*s = padded;
	return (width);
}
