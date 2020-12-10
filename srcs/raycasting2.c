/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:48:29 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/09 13:25:07 by cnavarro         ###   ########.fr       */
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

int		key_hook(int keycode, t_datos *dat)
{
	if (keycode == KEY_W)
	{
		if (dat->mapint[(int)(dat->rct->plposx + dat->rct->dirx * movespeed)][(int)dat->rct->plposy] == 0)
			dat->rct->plposx += dat->rct->dirx * movespeed;
		if (dat->mapint[(int)dat->rct->plposx][(int)(dat->rct->plposy + dat->rct->diry * movespeed)] == 0)
			dat->rct->plposy += dat->rct->diry * movespeed;
	}
	else if (keycode == KEY_S)
	{
		if (dat->mapint[(int)(dat->rct->plposx - dat->rct->dirx * movespeed)][(int)dat->rct->plposy] == 0)
			dat->rct->plposx -= dat->rct->dirx * movespeed;
		if (dat->mapint[(int)dat->rct->plposy][(int)(dat->rct->plposy - dat->rct->diry * movespeed)] == 0)
			dat->rct->plposy -= dat->rct->diry * movespeed;
	}
	else if (keycode == KEY_A)
	{
		if (dat->mapint[(int)(dat->rct->plposx - dat->rct->planex * movespeed)][(int)dat->rct->plposy] == 0)
			dat->rct->plposx -= dat->rct->planex * movespeed;
		if (dat->mapint[(int)dat->rct->plposx][(int)(dat->rct->plposy + dat->rct->planey * movespeed)] == 0)
			dat->rct->plposy -= dat->rct->planey * movespeed;
	}
	if (keycode == KEY_D)
	{
		if (dat->mapint[(int)(dat->rct->plposx + dat->rct->planex * movespeed)][(int)dat->rct->plposy] == 0)
			dat->rct->plposx += dat->rct->planex * movespeed;
		if (dat->mapint[(int)dat->rct->plposx][(int)(dat->rct->plposy + dat->rct->planey * movespeed)] == 0)
			dat->rct->plposy += dat->rct->planey * movespeed;
	}
	else if (keycode == KEY_RIGHT)
	{
		dat->rct->olddirx = dat->rct->dirx;
		dat->rct->dirx = dat->rct->dirx * cos(-rotspeed) - dat->rct->diry * sin(-rotspeed);
		dat->rct->diry = dat->rct->olddirx * sin(-rotspeed) + dat->rct->diry * cos(-rotspeed);
		dat->rct->oldplanex = dat->rct->planex;
		dat->rct->planex = dat->rct->planex * cos(-rotspeed) - dat->rct->planey * sin(-rotspeed);
		dat->rct->planey = dat->rct->oldplanex * sin(-rotspeed) + dat->rct->planey * cos(-rotspeed);
	}
	else if (keycode == KEY_LEFT)
	{
		dat->rct->olddirx = dat->rct->dirx;
		dat->rct->dirx = dat->rct->dirx * cos(rotspeed) - dat->rct->diry * sin(rotspeed);
		dat->rct->diry = dat->rct->olddirx * sin(rotspeed) + dat->rct->diry * cos(rotspeed);
		dat->rct->oldplanex = dat->rct->planex;
		dat->rct->planex = dat->rct->planex * cos(rotspeed) - dat->rct->planey * sin(rotspeed);
		dat->rct->planey = dat->rct->oldplanex * sin(rotspeed) + dat->rct->planey * cos(rotspeed);		
	}
	else if (keycode == KEY_ESCAPE)
	{
		//mlx_destroy_window(dat->mlx_ptr, dat->win_ptr); Da segmentation fault
		exit(16);
	}
	return (0);
}