/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:48:29 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/09 11:20:03 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int			ft_color(char *cadena)
{
	char	**aux;
	char	**colores;
	int		color;

	aux = ft_split(cadena, ' ');
	colores = ft_split(aux[1], ',');
	color = (ft_atoi(colores[0]) * 256 * 256 + ft_atoi(colores[1])
		* 256 + ft_atoi(colores[2]));
	ft_freematrix(aux);
	ft_freematrix(colores);
	return (color);
}

void		key_hook4(t_datos *dat)
{
	if (dat->right == 1)
	{
		dat->rct->olddirx = dat->rct->dirx;
		dat->rct->dirx = dat->rct->dirx * cos(-ROTSPEED)
			- dat->rct->diry * sin(-ROTSPEED);
		dat->rct->diry = dat->rct->olddirx * sin(-ROTSPEED)
			+ dat->rct->diry * cos(-ROTSPEED);
		dat->rct->oldplanex = dat->rct->planex;
		dat->rct->planex = dat->rct->planex * cos(-ROTSPEED)
			- dat->rct->planey * sin(-ROTSPEED);
		dat->rct->planey = dat->rct->oldplanex * sin(-ROTSPEED)
			+ dat->rct->planey * cos(-ROTSPEED);
	}
}

void		key_hook3(t_datos *dat)
{
	if (dat->keya == 1)
	{
		if (dat->mapint[(int)(dat->rct->plposx - dat->rct->planex * MOVESPEED)]
			[(int)dat->rct->plposy] == 0)
			dat->rct->plposx -= dat->rct->planex * MOVESPEED;
		if (dat->mapint[(int)dat->rct->plposx]
			[(int)(dat->rct->plposy - dat->rct->planey * MOVESPEED)] == 0)
			dat->rct->plposy -= dat->rct->planey * MOVESPEED;
	}
	if (dat->keyd == 1)
	{
		if (dat->mapint[(int)(dat->rct->plposx + dat->rct->planex * MOVESPEED)]
			[(int)dat->rct->plposy] == 0)
			dat->rct->plposx += dat->rct->planex * MOVESPEED;
		if (dat->mapint[(int)dat->rct->plposx]
			[(int)(dat->rct->plposy + dat->rct->planey * MOVESPEED)] == 0)
			dat->rct->plposy += dat->rct->planey * MOVESPEED;
	}
}

void		key_hook2(t_datos *dat)
{
	if (dat->keyw == 1)
	{
		if (dat->mapint[(int)(dat->rct->plposx + dat->rct->dirx * MOVESPEED)]
			[(int)dat->rct->plposy] == 0)
			dat->rct->plposx += dat->rct->dirx * MOVESPEED;
		if (dat->mapint[(int)dat->rct->plposx]
			[(int)(dat->rct->plposy + dat->rct->diry * MOVESPEED)] == 0)
			dat->rct->plposy += dat->rct->diry * MOVESPEED;
	}
	if (dat->keys == 1)
	{
		if (dat->mapint[(int)(dat->rct->plposx - dat->rct->dirx * MOVESPEED)]
			[(int)dat->rct->plposy] == 0)
			dat->rct->plposx -= dat->rct->dirx * MOVESPEED;
		if (dat->mapint[(int)dat->rct->plposx]
			[(int)(dat->rct->plposy - dat->rct->diry * MOVESPEED)] == 0)
			dat->rct->plposy -= dat->rct->diry * MOVESPEED;
	}
}

int			key_hook(t_datos *dat)
{
	key_hook2(dat);
	key_hook3(dat);
	key_hook4(dat);
	if (dat->left == 1)
	{
		dat->rct->olddirx = dat->rct->dirx;
		dat->rct->dirx = dat->rct->dirx * cos(ROTSPEED)
			- dat->rct->diry * sin(ROTSPEED);
		dat->rct->diry = dat->rct->olddirx * sin(ROTSPEED)
			+ dat->rct->diry * cos(ROTSPEED);
		dat->rct->oldplanex = dat->rct->planex;
		dat->rct->planex = dat->rct->planex * cos(ROTSPEED)
			- dat->rct->planey * sin(ROTSPEED);
		dat->rct->planey = dat->rct->oldplanex * sin(ROTSPEED)
			+ dat->rct->planey * cos(ROTSPEED);
	}
	return (0);
}
