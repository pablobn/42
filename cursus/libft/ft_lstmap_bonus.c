/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:37:35 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/05 20:47:05 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		new = ft_lstnew(0);
		if (!new)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		new->content = f(lst->content);
		ft_lstadd_back(&tmp, new);
		lst = lst->next;
	}
	return (tmp);
}
