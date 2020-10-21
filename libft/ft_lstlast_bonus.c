/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:28:24 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/15 13:45:59 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *var;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	var = lst;
	return (var);
}
