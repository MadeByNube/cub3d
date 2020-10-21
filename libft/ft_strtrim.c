/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:05:12 by cnavarro          #+#    #+#             */
/*   Updated: 2019/11/19 13:12:10 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_fill(int pos, int pos2, char *ret, char const *s1)
{
	int i;

	i = 0;
	while (pos != pos2)
	{
		ret[i] = s1[pos];
		pos++;
		i++;
	}
	ret[i] = '\0';
}

static int		startpos(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	pos;
	int flag;

	flag = 1;
	i = 0;
	j = 0;
	pos = 0;
	while (s1[i] != '\0' && flag == 1)
	{
		flag = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				pos++;
				flag = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (pos);
}

static int		finalpos(char const *s1, char const *set)
{
	int	i;
	int j;
	int pos;
	int flag;

	flag = 1;
	i = ft_strlen(s1);
	j = 0;
	pos = 0;
	while (i != 0 && flag == 1)
	{
		flag = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i - 1])
			{
				pos++;
				flag = 1;
			}
			j++;
		}
		j = 0;
		i--;
	}
	return (pos);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		pos2;
	int		pos;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen(s1);
	pos = startpos(s1, set);
	pos2 = i - finalpos(s1, set);
	if (pos2 < pos)
	{
		if (!(ret = malloc(sizeof(char))))
			return (ft_strdup(""));
		ret[0] = '\0';
		return (ret);
	}
	if (!(ret = malloc(sizeof(char) * (pos2 - pos) + 1)))
		return (NULL);
	i = 0;
	ft_fill(pos, pos2, ret, s1);
	return (ret);
}
