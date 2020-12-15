/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:48:29 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/15 14:49:52 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		ft_color(char *cadena)
{
	char **aux;
	char **colores;
	int color;

	aux = ft_split(cadena, ' ');
	colores = ft_split(aux[1], ',');
	color = (ft_atoi(colores[0]) * 256 * 256 + ft_atoi(colores[1]) * 256 + ft_atoi(colores[2]));
	ft_freematrix(aux);
	ft_freematrix(colores);
	return (color);
}

int		key_hook(t_datos *dat)
{
	if (dat->keyw == 1)
	{
		if (dat->mapint[(int)(dat->rct->plposx + dat->rct->dirx * movespeed)][(int)dat->rct->plposy] == 0)
			dat->rct->plposx += dat->rct->dirx * movespeed;
		if (dat->mapint[(int)dat->rct->plposx][(int)(dat->rct->plposy + dat->rct->diry * movespeed)] == 0)
			dat->rct->plposy += dat->rct->diry * movespeed;
	}
	if (dat->keys == 1)
	{
		if (dat->mapint[(int)(dat->rct->plposx - dat->rct->dirx * movespeed)][(int)dat->rct->plposy] == 0)
			dat->rct->plposx -= dat->rct->dirx * movespeed;
		if (dat->mapint[(int)dat->rct->plposx][(int)(dat->rct->plposy - dat->rct->diry * movespeed)] == 0)
			dat->rct->plposy -= dat->rct->diry * movespeed;
	}
	if (dat->keya == 1)
	{
		printf("%i \n", dat->mapint[(int)dat->rct->plposx][(int)(dat->rct->plposy + dat->rct->planey * movespeed)]);
		if (dat->mapint[(int)(dat->rct->plposx - dat->rct->planey * movespeed)][(int)dat->rct->plposy] == 0)
			dat->rct->plposx -= dat->rct->planex * movespeed;
		if (dat->mapint[(int)dat->rct->plposx][(int)(dat->rct->plposy + dat->rct->planex * movespeed)] == 0)
			dat->rct->plposy -= dat->rct->planey * movespeed;
	}
	if (dat->keyd == 1)
	{
		printf("%f-%f , %f-%f \n", dat->rct->plposx, dat->rct->plposx + movespeed, dat->rct->plposy, dat->rct->plposy + movespeed);
		if (dat->mapint[(int)(dat->rct->plposx + dat->rct->planex * movespeed)][(int)dat->rct->plposy] == 0)
			dat->rct->plposx += dat->rct->planex * movespeed;
		if (dat->mapint[(int)dat->rct->plposx][(int)(dat->rct->plposy + dat->rct->planey * movespeed)] == 0)
			dat->rct->plposy += dat->rct->planey * movespeed;
	}
	if (dat->right == 1)
	{
		dat->rct->olddirx = dat->rct->dirx;
		dat->rct->dirx = dat->rct->dirx * cos(-rotspeed) - dat->rct->diry * sin(-rotspeed);
		dat->rct->diry = dat->rct->olddirx * sin(-rotspeed) + dat->rct->diry * cos(-rotspeed);
		dat->rct->oldplanex = dat->rct->planex;
		dat->rct->planex = dat->rct->planex * cos(-rotspeed) - dat->rct->planey * sin(-rotspeed);
		dat->rct->planey = dat->rct->oldplanex * sin(-rotspeed) + dat->rct->planey * cos(-rotspeed);
	}
	if (dat->left == 1)
	{
		dat->rct->olddirx = dat->rct->dirx;
		dat->rct->dirx = dat->rct->dirx * cos(rotspeed) - dat->rct->diry * sin(rotspeed);
		dat->rct->diry = dat->rct->olddirx * sin(rotspeed) + dat->rct->diry * cos(rotspeed);
		dat->rct->oldplanex = dat->rct->planex;
		dat->rct->planex = dat->rct->planex * cos(rotspeed) - dat->rct->planey * sin(rotspeed);
		dat->rct->planey = dat->rct->oldplanex * sin(rotspeed) + dat->rct->planey * cos(rotspeed);		
	}
	return (0);
}