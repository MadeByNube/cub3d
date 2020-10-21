/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:46:13 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/19 13:16:42 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = str;
	i = 0;
	while (n > i)
	{
		a[i] = c;
		i++;
	}
	return (str);
}
