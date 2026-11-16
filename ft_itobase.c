/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:58:22 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 12:46:21 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	ft_nbr_base(char *c, unsigned long num, char *base, int *pos)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_nbr_base(c, num / base_len, base, pos);
	c[*pos] = base[num % base_len];
	*pos = *pos + 1;
}

char	*ft_itobase(unsigned int nbr, char *base_to)
{
	char	*c;
	int		start;

	if (!is_valid_base(base_to))
		return (NULL);
	start = 0;
	c = malloc(33 * sizeof(char));
	if (!c)
		return (NULL);
	ft_nbr_base(c, nbr, base_to, &start);
	c[start] = '\0';
	return (c);
}