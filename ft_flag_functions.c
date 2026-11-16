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

size_t left_justify(char **s, size_t width)
{
	if (ft_strlen(*s) >= width)
        return(width);
	*s = ft_strjoin(*s, ft_calloc(width - ft_strlen(*s) + 1, sizeof(char)));
	return(ft_strlen(s));
}

size_t force_sign(char **s, size_t width)
{
    if ((*s)[0] == '-')
        return(width);
    *s = ft_strjoin("+", *s);
	return(ft_strlen(s));
}

size_t signpad(char **s, size_t width)
{
    if((*s)[0] == '-' || (*s)[0] == '+')
        return(width);
	*s = ft_strjoin(" ", *s);
	return(ft_strlen(s));
}

size_t hex_memory(char **s, size_t width, int capitalize)
{
	*s = ft_strjoin("0x", *s);
	return(ft_strlen(s));
}

size_t zero_pad(char **s, size_t width)
{
	int i;
    
    i = 0;
    if (ft_strlen(*s) >= width)
        return (width);
    while (i < width - ft_strlen(*s))
    {
        *s = ft_strjoin("0", *s);
        i++;
    }
	return(ft_strlen(width));
}