/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:46:28 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/19 12:22:04 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (ret != NULL)
	{
		ret->content = (void *)content;
		ret->next = NULL;
	}
	return (ret);
}
