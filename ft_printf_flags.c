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

void initiateflags(t_flag **flag)
{
	(*flag)[0].c = '-';
	(*flag)[0].f = left_justify;
	(*flag)[1].c = '+';
	(*flag)[1].f = force_sign;
	(*flag)[2].c = ' ';
	(*flag)[2].f = signpad;
	(*flag)[3].c = '#';
	(*flag)[3].f = hex_memory;
	(*flag)[4].c = '0';
	(*flag)[4].f = zero_pad;
}
