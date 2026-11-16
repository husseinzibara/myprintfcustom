/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:45:14 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/16 08:47:17 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*ptr;
	void	*data;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		data = f(lst->content);
		ptr = ft_lstnew(data);
		if (!ptr)
		{
			del(data);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, ptr);
		lst = lst->next;
	}
	return (result);
}
