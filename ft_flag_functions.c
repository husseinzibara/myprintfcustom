/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:39:48 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 13:27:42 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

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
	size_t	p;
	char	*new;

	len = ft_strlen(*s);
	if (len >= width)
		return (len);
	p = ((*s)[0] == '-' || (*s)[0] == '+' || (*s)[0] == ' ');
	if ((*s)[p] == '0' && (*s)[p + 1] == 'x')
		p += 2;
	new = malloc(width + 1);
	if (!new)
		return (len);
	ft_memcpy(new, *s, p);
	ft_memset(new + p, '0', width - len);
	ft_strlcpy(new + p + (width - len), *s + p, len - p + 1);
	free(*s);
	*s = new;
	return (width);
}
