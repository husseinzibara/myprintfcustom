/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:40:33 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/18 09:30:38 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_nbr_base(char *c, unsigned long num, char *base, int *pos)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_nbr_base(c, num / base_len, base, pos);
	c[*pos] = base[num % base_len];
	*pos = *pos + 1;
}

char	*ft_itobase(unsigned long nbr, char *base_to)
{
	char	*c;
	int		start;

	if (!is_valid_base(base_to))
		return (NULL);
	start = 0;
	c = malloc(65 * sizeof(char));
	if (!c)
		return (NULL);
	ft_nbr_base(c, nbr, base_to, &start);
	c[start] = '\0';
	return (c);
}
