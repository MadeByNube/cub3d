/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:27:44 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/09 18:20:30 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if (c == '\0' && str[i] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == 0 && c == 0)
		return ((char *)&str[i]);
	return (NULL);
}
