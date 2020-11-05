/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveconfigerror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:00:38 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/05 12:12:27 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void    ft_saveorerror_r(t_datos *dat, char *line)
{
	if (dat->rflag == 1)
	{
		perror("Error\nResolucion duplicada");
		exit(12);
	}
	dat->r = ft_strdup(line);
	dat->rflag = 1;
}

void    ft_saveorerror_no(t_datos *dat, char *line)
{
	if (dat->noflag == 1)
	{
		perror("Error\nResolucion duplicada");
		exit(12);
	}
	dat->no = ft_strdup(line);
	dat->noflag = 1;
}

void    ft_saveorerror_so(t_datos *dat, char *line)
{
	if (dat->soflag == 1)
	{
		perror("Error\nResolucion duplicada");
		exit(12);
	}
	dat->so = ft_strdup(line);
	dat->soflag = 1;
}

void    ft_saveorerror_we(t_datos *dat, char *line)
{
	if (dat->weflag == 1)
	{
		perror("Error\nResolucion duplicada");
		exit(12);
	}
	dat->we = ft_strdup(line);
	dat->weflag = 1;
}