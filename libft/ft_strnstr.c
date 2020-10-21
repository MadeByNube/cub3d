/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:38:41 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/14 18:20:21 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;

	if (!*to_find)
		return ((char *)str);
	i = ft_strlen(to_find);
	while (*str && len-- >= i)
	{
		if (*str == *to_find && !ft_strncmp(str, to_find, i))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
