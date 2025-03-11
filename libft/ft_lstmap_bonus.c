/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:53 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:00:43 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*newelement;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		temp = f(lst->content);
		newelement = ft_lstnew(temp);
		if (!newelement)
		{
			ft_lstclear(&lst2, del);
			del(temp);
			return (NULL);
		}
		ft_lstadd_back(&lst2, newelement);
		lst = lst->next;
	}
	return (lst2);
}
