/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:01:39 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/05 13:00:06 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoingnl(char *str1, char car)
{
	char	*ret;
	int		len;
	int		pos;

	if (!str1 || !car)
		return (NULL);
	len = ft_strlen(str1);
	if (!(ret = malloc(sizeof(char) * (len + 1) + 1)))
		return (NULL);
	pos = 0;
	while (pos != len)
	{
		ret[pos] = str1[pos];
		pos++;
	}
	ret[pos] = car;
	pos++;
	ret[pos] = '\0';
	free(str1);
	return (ret);
}

int		getnextline(char **line, int fdmap)
{
	int		ret;
	char	buf[2];

	if (!line || !(*line = ft_strdup("")))
		return (-1);
	buf[1] = '\0';
	while ((ret = read(fdmap, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
			break ;
		*line = ft_strjoingnl(*line, buf[0]);
	}
	return (ret);
}
