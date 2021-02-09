/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:23:53 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/09 10:03:00 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_focmaximo(char **aux2)
{
	int	x;

	x = 0;
	while (aux2[x])
	{
		if (ft_atoi(aux2[x]) < 0 || ft_atoi(aux2[x]) > 255)
		{
			perror("Error\nColor incorrecto");
		}
		x++;
	}
}

char	*ft_convtexture(char *texture)
{
	int		i;
	int		j;
	char	*aux;

	aux = ft_calloc(sizeof(char *) * ft_strlen(texture), 1);
	i = 0;
	j = 0;
	while (texture[i] != '.' && texture[i + 1] != '/')
		i++;
	while (texture[i])
		aux[j++] = texture[i++];
	aux[j] = '\0';
	return (aux);
}
