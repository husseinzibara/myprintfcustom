/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 06:44:40 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 08:34:44 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l1;
	size_t	l2;

	l1 = 0;
	l2 = 0;
	while (src[l1] != '\0')
		l1++;
	while (dest[l2] != '\0' && l2 < size)
		l2++;
	i = 0;
	while (src[i] != '\0' && i + 1 < (size - l2))
	{
		dest[l2 + i] = src[i];
		i++;
	}
	if (i < size - l2)
		dest[l2 + i] = '\0';
	return (l1 + l2);
}
