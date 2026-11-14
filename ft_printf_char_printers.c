/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_printers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:27:17 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/14 16:21:19 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void printstr(char *s, char **output, char *mods, int *totalwidth, t_flag **flags)
{
    int i;
    int j;

    i = 0;
    while (mods[i] != '\0')
    {
        j = 0;
        while (flags[j].c != '\0')
        {
            if (mods[i] == flags[j].c)
                flags[j].f(&s, *totalwidth);
            j++;
        }
        i++;
    }
    *output = ft_strjoin(*output, s);
    *totalwidth += ft_strlen(s);
    free(s);
}

void printchar(char c , char **output, char *mods, int *totalwidth, t_flag **flags)


void printhex(int* num, char **output, char *mods, int *totalwidth, t_flag **flags)


void printHEX(int* num, char **output, char *mods, int *totalwidth, t_flag **flags)

