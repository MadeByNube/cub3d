/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:11:33 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/08 13:00:26 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_rays4(t_datos *dat)
{
	dat->rct->lineheight = (int)(dat->r2 / dat->rct->perpwalldist);
	dat->rct->drawstart = -dat->rct->lineheight / 2 + dat->r2 / 2;
	if (dat->rct->drawstart < 0)
		dat->rct->drawstart = 0;
	dat->rct->drawend = dat->rct->lineheight / 2 + dat->r2 / 2;
	if (dat->rct->drawend >= dat->r2)
		dat->rct->drawend = dat->r2 - 1;
	if (dat->rct->side == 0)
		dat->wallx = dat->rct->plposy
			+ dat->rct->perpwalldist * dat->rct->raydiry;
	else
		dat->wallx = dat->rct->plposx
			+ dat->rct->perpwalldist * dat->rct->raydirx;
	dat->wallx -= floor(dat->wallx);
	if (dat->rct->side == 0 && dat->rct->raydirx > 0)
		dat->text = 0;
	if (dat->rct->side == 0 && dat->rct->raydirx <= 0)
		dat->text = 1;
	if (dat->rct->side == 1 && dat->rct->raydiry > 0)
		dat->text = 2;
	if (dat->rct->side == 1 && dat->rct->raydiry <= 0)
		dat->text = 3;
	dat->tex_x = (int)(dat->wallx * (double)dat->tex[dat->text].width);
}

void	ft_rays3(t_datos *dat)
{
	while (dat->rct->hit == 0)
	{
		if (dat->rct->sidedistx < dat->rct->sidedisty)
		{
			dat->rct->sidedistx += dat->rct->deltadistx;
			dat->rct->mapx += dat->rct->stepx;
			dat->rct->side = 0;
		}
		else
		{
			dat->rct->sidedisty += dat->rct->deltadisty;
			dat->rct->mapy += dat->rct->stepy;
			dat->rct->side = 1;
		}
		if (dat->mapint[dat->rct->mapx][dat->rct->mapy] > 0)
			dat->rct->hit = 1;
	}
	if (dat->rct->side == 0)
		dat->rct->perpwalldist = (dat->rct->mapx - dat->rct->plposx
			+ (1 - dat->rct->stepx) / 2) / dat->rct->raydirx;
	else
		dat->rct->perpwalldist = (dat->rct->mapy - dat->rct->plposy
			+ (1 - dat->rct->stepy) / 2) / dat->rct->raydiry;
}

void	ft_rays2(t_datos *dat)
{
	if (dat->rct->raydirx < 0)
	{
		dat->rct->stepx = -1;
		dat->rct->sidedistx = (dat->rct->plposx - dat->rct->mapx)
			* dat->rct->deltadistx;
	}
	else
	{
		dat->rct->stepx = 1;
		dat->rct->sidedistx = (dat->rct->mapx + 1.0 - dat->rct->plposx)
			* dat->rct->deltadistx;
	}
	if (dat->rct->raydiry < 0)
	{
		dat->rct->stepy = -1;
		dat->rct->sidedisty = (dat->rct->plposy - dat->rct->mapy)
			* dat->rct->deltadisty;
	}
	else
	{
		dat->rct->stepy = 1;
		dat->rct->sidedisty = (dat->rct->mapy + 1.0 - dat->rct->plposy)
			* dat->rct->deltadisty;
	}
}

void	ft_rays1(t_datos *dat, int x)
{
	dat->rct->camx = 2 * x / (double)(dat->r1) - 1;
	dat->rct->raydirx = dat->rct->dirx + dat->rct->planex * dat->rct->camx;
	dat->rct->raydiry = dat->rct->diry + dat->rct->planey * dat->rct->camx;
	dat->rct->mapx = (int)dat->rct->plposx;
	dat->rct->mapy = (int)dat->rct->plposy;
	dat->rct->deltadistx = fabs(1 / dat->rct->raydirx);
	dat->rct->deltadisty = fabs(1 / dat->rct->raydiry);
	dat->rct->hit = 0;
}

void	ft_rays(t_datos *dat)
{
	int x;

	x = 0;
	while (x < dat->r1)
	{
		ft_rays1(dat, x);
		ft_rays2(dat);
		ft_rays3(dat);
		ft_rays4(dat);
		if (dat->rct->side == 0 && dat->rct->raydirx > 0)
			dat->tex_x = dat->tex[dat->text].width - dat->tex_x - 1;
		if (dat->rct->side == 1 && dat->rct->raydiry < 0)
			dat->tex_x = dat->tex[dat->text].width - dat->tex_x - 1;
		dat->step = 1.0 * dat->tex[dat->text].height / dat->rct->lineheight;
		dat->texpos = (dat->rct->drawstart - dat->r2
			/ 2 + dat->rct->lineheight / 2) * dat->step;
		ft_verline(x, dat);
		x++;
	}
	ft_spritesbucle(dat);
}
