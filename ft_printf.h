/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 13:28:22 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h" /* ft_putstr_fd, ft_itoa, ft_strlen */
# include <stdarg.h> /* va_list, va_start, va_arg, va_end */
# include <stdlib.h> /* free */
# include <unistd.h> /* write */

int		ft_printf(const char *fmt, ...);
int		printchar(int c);
int		printstr(char *s);
int		printnum(int num);
int		printbase(unsigned long num, char *base);
int		printptr(void *ptr);
char	*ft_itobase(unsigned long nbr, char *base_to);

#endif
