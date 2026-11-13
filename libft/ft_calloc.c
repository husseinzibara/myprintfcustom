/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:33:05 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/11 10:18:40 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*data;
	size_t			i;

	i = 0;
	if (nmemb && (size > __SIZE_MAX__ / nmemb))
		return (NULL);
	data = malloc(nmemb * size);
	if (!data)
		return (NULL);
	while (i < nmemb * size)
		data[i++] = 0;
	return ((void *)data);
}
