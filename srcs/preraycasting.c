/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preraycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:58:03 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/05 12:48:31 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_preraycasting(t_datos *dat)
{
	ft_intmap(dat);
	ft_configadd(dat);
	ft_prerays(dat);
	ft_presprites(dat);
}

void	ft_intmap(t_datos *dat)
{
	int x;
	int y;
	int l;

	x = 0;
	dat->mapint = ft_calloc(sizeof(int *), (dat->filmap) + 1);
	while (dat->mapa[x] != '\0')
	{
		l = (ft_strlen(dat->mapa[x]));
		dat->mapint[x] = ft_calloc(sizeof(int), l);
		y = 0;
		while (dat->mapa[x][y] != '\0')
		{
			if (dat->mapa[x][y] == '0' || dat->mapa[x][y] == 'N' ||
				dat->mapa[x][y] == 'S' || dat->mapa[x][y] == 'E' ||
					dat->mapa[x][y] == 'W')
				dat->mapint[x][y] = 0;
			else if (dat->mapa[x][y] == '1')
				dat->mapint[x][y] = 1;
			else if (dat->mapa[x][y] == ' ')
				dat->mapint[x][y] = 0;
			y++;
		}
		x++;
	}
}

void	ft_configadd(t_datos *dat)
{
	char **aux;

	aux = ft_split(dat->r, ' ');
	dat->r1 = ft_atoi(aux[1]);
	dat->r2 = ft_atoi(aux[2]);
	if (dat->r1 > INT32_MAX || dat->r2 > INT32_MAX)
	{
		perror("Error:\nResolucion incorrecta");
		exit(30);
	}
	if (dat->r1 > 2560 && dat->save == 0)
		dat->r1 = 2560;
	if (dat->r2 > 1440 && dat->save == 0)
		dat->r2 = 1440;
	ft_freematrix(aux);
	dat->keyw = 0;
	dat->keys = 0;
	dat->keyd = 0;
	dat->keya = 0;
	dat->left = 0;
	dat->right = 0;
	dat->zbuffer = ft_calloc(sizeof(double), dat->r1);
}

void	ft_prerays(t_datos *dat)
{
	ft_dirpos(dat);
}

int		ft_keypress(int key, t_datos *dat)
{
	if (key == KEY_W)
		dat->keyw = 1;
	if (key == KEY_S)
		dat->keys = 1;
	if (key == KEY_D)
		dat->keyd = 1;
	if (key == KEY_A)
		dat->keya = 1;
	if (key == KEY_LEFT)
		dat->left = 1;
	if (key == KEY_RIGHT)
		dat->right = 1;
	if (key == KEY_ESCAPE)
		ft_exit(dat);
	return (0);
}
