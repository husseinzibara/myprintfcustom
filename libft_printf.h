/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:54:42 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 12:46:25 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

#include "libft/libft.h"
# include <stdarg.h>

size_t left_justify(char **s, size_t width);
size_t force_sign(char **s, size_t width);
size_t signpad(char **s, size_t width);
size_t hex_memory(char **s, size_t width, int capitalize);
size_t zero_pad(char **s, size_t width);
char	*ft_itobase(unsigned int nbr, char *base_to);

typedef struct s_flag
{
	char	c;
	int 	(*f)(char **, int);
} t_flag;


#endif