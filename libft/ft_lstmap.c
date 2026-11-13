/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzibara <hzibara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:45:14 by hzibara           #+#    #+#             */
/*   Updated: 2026/11/11 10:16:44 by hzibara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		ptr = ft_lstnew(f((*lst).content));
		if (!ptr)
		{
			del(ptr->content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, ptr);
		lst = lst->next;
	}
	return (result);
}
