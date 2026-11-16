/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_printers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 10:27:17 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 13:27:17 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void printstr(char *s, int *width, char *mods, t_flag **flags)
{
    int i;
    int j;

    i = 0;
    while (mods[i] != '\0')
    {
        j = 0;
        while (flags[j]->c != '\0')
        {
            if (mods[i] == flags[j]->c)
                *width += flags[j]->f(&s, width);
            j++;
        }
        i++;
    }
	ft_putstr_fd(s, 1);
    free(s);
}

void printchar(char c ,int *width, char *mods, t_flag **flags)
{
	int		i;
    int		j;
	char	*s;

    i = 0;
	s[0] = c;
    while (mods[i])
    {
        j = 0;
        while (flags[j]->c != '\0')
        {
            if (mods[i] == flags[j]->c)
                *width += flags[j]->f(&s, width);
            j++;
        }
        i++;
    }
	ft_putstr_fd(s, 1);
    free(s);
}

void printhex(int* num,int *width, char *mods, t_flag **flags)
{
	int		i;
    int		j;
	char	*s;

    i = 0;
	s = ft_itobase(num, "0123456789abcdef");
    while (mods[i])
    {
        j = 0;
        while (flags[j]->c != '\0')
        {
            if (mods[i] == flags[j]->c)
                *width += flags[j]->f(&s, width);
            j++;
        }
        i++;
    }
	ft_putstr_fd(s, 1);
    free(s);
}

void printHEX(int* num,int *width, char *mods, t_flag **flags)
{
	int		i;
    int		j;
	char	*s;

    i = 0;
	s = ft_itobase(num, "0123456789ABCDEF");
    while (mods[i])
    {
        j = 0;
        while (flags[j]->c != '\0')
        {
            if (mods[i] == flags[j]->c)
                *width += flags[j]->f(&s, width);
            j++;
        }
        i++;
    }
	i = -1;
	while (s[++i])
	ft_toupper(s[i]);
    free(s);
}