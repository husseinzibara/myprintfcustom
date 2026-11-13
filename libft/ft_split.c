/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:00:23 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/11 11:10:47 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	allfree(char **set, int x)
{
	int	i;

	i = -1;
	while (++i < x)
		free(set[i]);
	free(set);
}

static int	strcnt(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*getword(const char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = s[len];
	return (word);
}

static char	**fillset(const char *s, char c, char **set)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			set[k] = getword(s + i, c);
			if (!set[k])
			{
				allfree(set, k);
				return (NULL);
			}
			k++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	set[k] = NULL;
	return (set);
}

char	**ft_split(const char *s, char c)
{
	char	**set;

	if (!s)
		return (NULL);
	set = malloc((strcnt(s, c) + 1) * sizeof(char *));
	if (!set)
		return (NULL);
	return (fillset(s, c, set));
}
