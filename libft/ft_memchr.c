/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:12:37 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/09 13:17:46 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int ch, size_t n)
{
	size_t			i;
	unsigned char	*origen;

	origen = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (origen[i] == (unsigned char)ch)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
