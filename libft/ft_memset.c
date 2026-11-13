/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:35:27 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/11 09:44:28 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *)s;
	while (n > 0)
	{
		*dst = (unsigned char)c;
		dst++;
		n--;
	}
	return (s);
}
