/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:37:30 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/03 12:24:53 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	void	*ptr;

	ptr = malloc(n * s);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, n * s);
	return (ptr);
}
