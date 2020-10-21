/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:46:48 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/13 11:19:58 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *cad)
{
	char	*new;
	int		len;

	len = 0;
	len = ft_strlen(cad);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (cad[len])
	{
		new[len] = cad[len];
		len++;
	}
	new[len] = '\0';
	return (new);
}
