/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:48:16 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/16 12:39:27 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*aux;

	(void)(*del);
	if (!lst)
		return (NULL);
	if (!f)
		return (NULL);
	aux = ft_lstnew(f(lst->content));
	if (!aux)
		return (NULL);
	ret = aux;
	while (lst->next != NULL)
	{
		lst = lst->next;
		aux->next = ft_lstnew(f(lst->content));
		if (aux->next == NULL)
			return (NULL);
		aux = aux->next;
	}
	return (ret);
}
