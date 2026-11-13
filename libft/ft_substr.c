/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:46:30 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/11 10:55:55 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sp;
	size_t	l;
	size_t	i;

	l = ft_strlen((char *)s);
	if (start >= l)
		len = 0;
	else if (len > l - start)
		len = l - start;
	sp = malloc(len + 1);
	if (!sp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sp[i] = s[start + i];
		i++;
	}
	sp[i] = '\0';
	return (sp);
}
