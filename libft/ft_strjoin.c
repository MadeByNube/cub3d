/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:39:07 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/18 17:48:12 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ret = malloc(sizeof(char) * (i + j) + 1)))
		return (NULL);
	k = 0;
	while (k != i)
	{
		ret[k] = s1[k];
		k++;
	}
	while (k != j + i)
	{
		ret[k] = s2[k - i];
		k++;
	}
	ret[k] = '\0';
	return (ret);
}
