/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:23:53 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/09 11:11:06 by cnavarro         ###   ########.fr       */
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

void	ft_correctconfig(t_datos *dat)
{
	if (!dat->r || !dat->no || !dat->so || !dat->we
		|| !dat->ea || !dat->s || !dat->f || !dat->c)
	{
		perror("Error\nConfiguracion incompleta");
		exit(13);
	}
}

void	ft_quitaespacios2000f(t_datos *dat)
{
	int		i;
	int		pos;
	char	*aux;

	aux = ft_calloc(sizeof(char *) * ft_strlen(dat->f), 1);
	pos = 0;
	i = 0;
	while (dat->f[pos] == ' ')
		pos++;
	aux[i++] = dat->f[pos++];
	aux[i++] = dat->f[pos++];
	while (dat->f[pos])
	{
		if (dat->f[pos] == ' ')
			pos++;
		else
			aux[i++] = dat->f[pos++];
	}
	dat->fnew = ft_strdup(aux);
	free(aux);
}

void	ft_quitaespacios2000c(t_datos *dat)
{
	int		i;
	int		pos;
	char	*aux;

	aux = ft_calloc(sizeof(char *) * ft_strlen(dat->c), 1);
	pos = 0;
	i = 0;
	while (dat->c[pos] == ' ')
		pos++;
	aux[i++] = dat->c[pos++];
	aux[i++] = dat->c[pos++];
	while (dat->c[pos])
	{
		if (dat->c[pos] == ' ')
			pos++;
		else
			aux[i++] = dat->c[pos++];
	}
	dat->cnew = ft_strdup(aux);
	free(aux);
}
