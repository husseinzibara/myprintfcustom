/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/18 08:47:35 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h> 
# include <stdlib.h> 
# include <unistd.h> 

int		ft_printf(const char *fmt, ...);
int		printchar(int c);
int		printstr(char *s);
int		printnum(int num);
int		printbase(unsigned long num, char *base);
int		printptr(void *ptr);
char	*ft_itobase(unsigned long nbr, char *base_to);

#endif
