/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:49:51 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/11 09:34:50 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*fin;

	if (!s)
		return (0);
	fin = 0;
	while (*s)
	{
		if (*s == (char)c)
			fin = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (fin);
}
