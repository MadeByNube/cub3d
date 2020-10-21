/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:50:46 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/09 19:55:58 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*cad;
	size_t			i;

	cad = (unsigned char *)str;
	i = 0;
	while (n > i)
	{
		cad[i] = '\0';
		i++;
	}
}
