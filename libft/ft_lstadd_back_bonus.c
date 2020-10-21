/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:39:59 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/18 17:45:20 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*aux;

	aux = *alst;
	if (aux != NULL)
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
		new->next = NULL;
	}
	else
	{
		*alst = new;
		new->next = NULL;
	}
}
