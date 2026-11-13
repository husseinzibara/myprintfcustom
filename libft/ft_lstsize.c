/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:24:17 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/10 13:49:48 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*node;

	size = 0;
	if (lst == NULL)
		return (0);
	node = lst;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}
