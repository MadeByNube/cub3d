/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:53:56 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/13 13:52:46 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *destino, const void *origen, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*orig;

	if (!destino && !origen)
		return (NULL);
	dest = (unsigned char *)destino;
	orig = (unsigned char *)origen;
	i = 0;
	while (n > i)
	{
		dest[i] = orig[i];
		i++;
	}
	return (dest);
}
