/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 13:28:22 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h" /* ft_* helpers, size_t */
# include <stdarg.h> /* va_list, va_start, va_arg, va_end */
# include <stdlib.h> /* malloc, free */
# include <unistd.h> /* write */

typedef struct s_flag
{
	char	c;
	size_t	(*f)(char **s, size_t width);
}			t_flag;

typedef struct s_spec
{
	int		width;
	int		prec;
	char	mods[9];
}			t_spec;

size_t	left_justify(char **s, size_t width);
size_t	force_sign(char **s, size_t width);
size_t	signpad(char **s, size_t width);
size_t	hex_memory(char **s, size_t width);
size_t	zero_pad(char **s, size_t width);
size_t	right_justify(char **s, size_t width);
void	initiateflags(t_flag *flag);
void	filter_mods(char *mods, char *allowed);
size_t	apply_flags(char **s, size_t width, char *mods, t_flag *flags);
void	apply_prec(char **s, t_spec *spec, int is_zero);
char	*trim_str(char *s, int prec);
char	*ft_itobase(unsigned long nbr, char *base_to);
int		ft_printf(const char *fmt, ...);
int		printstr(char *s, t_spec *spec, t_flag *flags);
int		printchar(int c, t_spec *spec, t_flag *flags);
int		printhex(unsigned int num, t_spec *spec, t_flag *flags);
int		printhex_upper(unsigned int num, t_spec *spec, t_flag *flags);
int		printptr(void *ptr, t_spec *spec, t_flag *flags);
int		printnum(int num, t_spec *spec, t_flag *flags);
int		printuint(unsigned int num, t_spec *spec, t_flag *flags);

#endif
