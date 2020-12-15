/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preraycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:58:03 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/15 12:42:57 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_preraycasting(t_datos *dat)
{
	ft_intmap(dat);
	ft_configadd(dat);
	ft_prerays(dat);
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
				dat->mapint[x][y] = 4;
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
	dat->posx = 450;
	dat->posy = 250;
	free(aux);
	dat->keyw = 0;
	dat->keys = 0;
	dat->keyd = 0;
	dat->keya = 0;
	dat->left = 0;
	dat->right = 0;
}

void	ft_texturas(t_datos *dat)
{
	char **aux;

	aux = ft_split(dat->no, ' ');
	dat->texture = mlx_xpm_file_to_image(dat->mlx_ptr, aux[1], &dat->text_width, &dat->text_width);
	exit(1);
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