/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:48:07 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/11 10:08:04 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	return (ft_memcpy(result, s, size + 1));
}
