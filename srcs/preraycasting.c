/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preraycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:58:03 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/22 12:33:11 by cnavarro         ###   ########.fr       */
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
			if	(dat->mapa[x][y] == '0' || dat->mapa[x][y] == 'N' || dat->mapa[x][y] == 'S' || dat->mapa[x][y] == 'E' || dat->mapa[x][y] == 'W')
				dat->mapint[x][y] = 0;
			else if	(dat->mapa[x][y] == '1')
				dat->mapint[x][y] = 1;
			else if (dat->mapa[x][y] == ' ')
				dat->mapint[x][y] = 0;
			y++;
		}
		x++;
	}
	// imprimir mapa solo comprobación
	/*
	x = 0;
	y = 0;
	while (dat->mapa[x])
	{
		while (dat->mapa[x][y])
		{
			printf("%c", (dat->mapa[x][y]));
			y++;
		}
		printf("\n");
		x++;
		y = 0;
	}
	x = 0;
	y = 0;
	while (dat->mapint[x])
	{
		while (dat->mapint[x][y])
		{
			printf("%i", (dat->mapint[x][y]));
			y++;
		}
		printf("\n");
		x++;
		y = 0;
	}*/
}
void	ft_configadd(t_datos *dat)
{
	char **aux;
	aux = ft_split(dat->r, ' ');
	dat->r1 = ft_atoi(aux[1]);
	dat->r2 = ft_atoi(aux[2]);
	free(aux);
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
void	ft_dirpos(t_datos *dat)
{
	if (dat->cardinal == 'N')
	{
		dat->rct->dirx = -1;
		dat->rct->diry = 0;
		dat->rct->planex = 0;
		dat->rct->planey = 0.66;
	}
	else if (dat->cardinal == 'S')
	{
		dat->rct->dirx = 1;
		dat->rct->diry = 0;
		dat->rct->planex = 0;
		dat->rct->planey = -0.66;
	}
	else if (dat->cardinal == 'W')
	{
		dat->rct->dirx = 0;
		dat->rct->diry = -1;
		dat->rct->planex = -0.66;
		dat->rct->planey = 0;
	}
	else if (dat->cardinal == 'E')
	{
		dat->rct->dirx = 0;
		dat->rct->diry = 1;
		dat->rct->planex = 0.66;
		dat->rct->planey = 0;
	}
}

int	ft_keypress(int key, t_datos *dat)
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
	return(0);
}

int	ft_keyrelease(int key, t_datos *dat)
{
	if (key == KEY_W)
		dat->keyw = 0;
	if (key == KEY_S)
		dat->keys = 0;
	if (key == KEY_D)
		dat->keyd = 0;
	if (key == KEY_A)
		dat->keya = 0;
	if (key == KEY_LEFT)
		dat->left = 0;
	if (key == KEY_RIGHT)
		dat->right = 0;
	return(0);
}

void	ft_exit(t_datos *dat)
{
	mlx_destroy_window(dat->mlx_ptr, dat->win_ptr);
	dat->mlx_ptr = NULL;
	free(dat->mlx_ptr);
	exit(19);
}

void	ft_presprites(t_datos *dat)
{
	int i;

	i = 0;
	dat->sprcount = ft_count2(dat);
	dat->sprarray = ft_calloc(sizeof(int *), dat->sprcount);
	while (i < dat->sprcount)
	{
		dat->sprarray[i] = ft_calloc(sizeof(int), 2);
		i++;
	}
	ft_arraylogs(dat);
	dat->zbuffer = ft_calloc(sizeof(double), dat->r2);
	dat->spr_ord = ft_calloc(sizeof(int), dat->sprcount);
	dat->spr_dist = ft_calloc(sizeof(double), dat->sprcount);
}

int	ft_count2(t_datos *dat)
{
	int count;
	int x;
	int y;

	x = 0;
	y = 0;
	count = 0;

	while (dat->mapa[x])
	{
		while (dat->mapa[x][y])
		{
			if (dat->mapa[x][y] == '2')
				count++;
			y++;
		}
		y = 0;
		x++;
	}
	return (count);
}

void	ft_arraylogs(t_datos *dat)
{
	int x;
	int y;
	int count;

	x = 0;
	y = 0;
	count = 0;

	while (dat->mapa[x])
	{
		while (dat->mapa[x][y])
		{
			if (dat->mapa[x][y] == '2')
			{
				dat->sprarray[count][0] = x;
				dat->sprarray[count][1] = y;
				count++;
			}
			y++;
		}
		x++;
		y = 0;
	}
}