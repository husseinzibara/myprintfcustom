/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:10:10 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/11 10:17:20 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sp1;
	const unsigned char	*sp2;
	const unsigned char	*end;

	if (n == 0)
		return (0);
	sp1 = (const unsigned char *)s1;
	sp2 = (const unsigned char *)s2;
	end = (const unsigned char *)s1 + n - 1;
	while ((*sp1) == (*sp2) && sp1 != end)
	{
		sp1++;
		sp2++;
	}
	return ((*sp1) - (*sp2));
}
