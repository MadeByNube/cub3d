/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:33:01 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/03 12:21:25 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void ft_initializedat(t_datos *dat)
{
	dat->mapa = NULL;
	dat->filmap = 0;
	dat->r = NULL;
	dat->no = NULL;
	dat->so = NULL;
	dat->we = NULL;
	dat->ea = NULL;
	dat->s = NULL;
	dat->f = NULL;
	dat->c = NULL;
	dat->mapname = NULL;
	dat->r = 0;
	dat->no = 0;
	dat->so = 0;
	dat->we = 0;
	dat->ea = 0;
	dat->s = 0;
	dat->f = 0;
	dat->c = 0;
	dat->rflag = 0;
	dat->noflag = 0;
	dat->soflag = 0;
	dat->weflag = 0;
	dat->eaflag = 0;
	dat->sflag = 0;
	dat->fflag = 0;
	dat->cflag = 0;
	dat->nomaplines = 0;
	dat->initmaplane = NULL;
}

static int	ft_contarfilas(int fdmap)
{
	int i;
	char *line;

	line = NULL;
	i = 1;
	while (((getnextline(&line, fdmap)) > 0) && (ft_strncmp(line, "\n", ft_strlen(line)) == 1))
		free(line);
	free(line);
	while((getnextline(&line, fdmap)) > 0)
	{
		i++;
		free(line);
	}
	i = i + 2;
	free(line);
	return (i);
}

void	ft_savemap(t_datos *dat, int fdmap)
{
	char *line;
	int i;
	int cont;

	cont = 0;
	i = 0;
	line = NULL;
	while (cont++ < dat->nomaplines)
	{
		getnextline(&line, fdmap);
		free(line);
	}
	while (((getnextline(&line, fdmap)) > 0) && (ft_strncmp(line, "\n", ft_strlen(line)) == 0))
		free(line);
	dat->mapa[i] = ft_strdup(line);
	i++;
	while (i < dat->filmap)
	{
		getnextline(&dat->mapa[i], fdmap);
		i++;
	}
	dat->mapa[i] = NULL;
	free(line);
}

void		ft_genmap(char *archivo, t_datos *dat)
{
	int fdmap;

	ft_initializedat(dat);
	if (!(fdmap = open(archivo, O_RDONLY)))
	{
		perror("Error\nNo se ha podido leer el archivo");
		exit(9);
	}
	ft_saveconfig(fdmap, dat);
	ft_correctconfig(dat);
	dat->filmap = ft_contarfilas(fdmap);
	close(fdmap);
	fdmap = open(archivo, O_RDONLY);
	dat->mapa = ft_calloc(sizeof(char **) * (dat->filmap + 1), 1);
	ft_savemap(dat, fdmap);
	close(fdmap);
}
