/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:07 by cnavarro          #+#    #+#             */
/*   Updated: 2020/09/23 10:26:09 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	unsigned int	i;
	size_t			size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if(!(aux = malloc(len + 1)))
		return (NULL);
	if (start < size)
	{
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			aux[i] = s[start + i];
			i++;
		}
		aux[i] = '\0';
	}
	else
		return (ft_strdup(""));
	return (aux);
}
