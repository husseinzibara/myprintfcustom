/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:54:42 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/14 08:55:58 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

#include "libft/libft.h"
# include <stdarg.h>


typedef struct s_flag
{
	char	c;
	int 	(*f)(va_list *);
} t_flag;

int		ft_printf(const char *, ...);
void	left_justify(char **s, size_t minwidth);
void	force_sign(char **s, size_t minwidth);
void	sign_pad(char **s, size_t minwidth);
void	mem_float(char **s, size_t minwidth);
void	zero_pad(char **s, size_t minwidth);
void	initiateflags(t_flag **flag);

#endif