/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:29:41 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/14 19:57:14 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	int				lens;
	unsigned int	i;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (!(ret = malloc(sizeof(char) * lens + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
