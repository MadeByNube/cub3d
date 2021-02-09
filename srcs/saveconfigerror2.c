/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveconfigerror2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:10:06 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/09 10:40:07 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_saveorerror_ea(t_datos *dat, char *line)
{
	if (dat->eaflag == 1)
	{
		perror("Error\nTextura EA duplicada");
		exit(12);
	}
	dat->ea = ft_strdup(line);
	dat->eaflag = 1;
}

void	ft_saveorerror_s(t_datos *dat, char *line)
{
	if (dat->sflag == 1)
	{
		perror("Error\nTextura S duplicada");
		exit(12);
	}
	dat->s = ft_strdup(line);
	dat->sflag = 1;
}

void	ft_saveorerror_f(t_datos *dat, char *line)
{
	if (dat->fflag == 1)
	{
		perror("Error\nColor floor duplicada");
		exit(12);
	}
	dat->f = ft_strdup(line);
	dat->fflag = 1;
}

void	ft_saveorerror_c(t_datos *dat, char *line)
{
	if (dat->cflag == 1)
	{
		perror("Error\nColor Ceiling  duplicada");
		exit(12);
	}
	dat->c = ft_strdup(line);
	dat->cflag = 1;
}
