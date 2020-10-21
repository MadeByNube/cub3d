/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:54:50 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/19 11:51:44 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*mdst;
	const unsigned char	*msrc;

	mdst = (unsigned char *)dst;
	msrc = (const unsigned char *)src;
	if (n)
	{
		while (n-- != 0)
			if ((*mdst++ = *msrc++) == (unsigned char)c)
				return (mdst);
	}
	return (NULL);
}
