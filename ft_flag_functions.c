/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:39:48 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/14 16:14:55 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void left_justify(char **s, size_t minwidth)
{
	if (ft_strlen(*s) >= minwidth)
        return;
    else
        *s = ft_strjoin(*s, ft_calloc(minwidth - ft_strlen(*s) + 1, sizeof(char)));
}

void force_sign(char **s, size_t minwidth)
{
    if ((*s)[0] == '-')
        return;
    else
        *s = ft_strjoin("+", *s);
}

void signpad(char **s, size_t minwidth)
{
    if((*s)[0] == '-' || (*s)[0] == '+')
        return;
    else
        *s = ft_strjoin(" ", *s);
}

void hex_memory(char **s, size_t minwidth)
{
    *s = ft_strjoin("0x", *s);
}

void zero_pad(char **s, size_t minwidth)
{
	int i;
    
    i = 0;
    if (ft_strlen(*s) >= minwidth)
        return;
    else
    {
        while (i < minwidth - ft_strlen(*s))
        {
            *s = ft_strjoin("0", *s);
            i++;
        }
    }
}