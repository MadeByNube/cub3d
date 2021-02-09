/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:49:33 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/08 13:01:35 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_verline(int x, t_datos *dat)
{
	int y;
	int floor;
	int ceiling;

	floor = ft_color(dat->f);
	ceiling = ft_color(dat->c);
	y = -1;
	dat->zbuffer[x] = dat->rct->perpwalldist;
	while (++y < dat->rct->drawstart)
		ft_mlx_pixel_put(dat, x, y, floor);
	while (y < dat->rct->drawend)
	{
		dat->texy = (int)dat->texpos & (dat->tex[dat->text].height - 1);
		dat->texpos += dat->step;
		ft_mlx_pixel_put(dat, x, y, ft_pixel_get(dat, dat->tex_x, dat->texy));
		y++;
	}
	while (y < dat->r2)
	{
		ft_mlx_pixel_put(dat, x, y, ceiling);
		y++;
	}
}

void	ft_spritesbucle(t_datos *dat)
{
	int i;

	i = 0;
	ft_sortsprites(dat);
	while (i < dat->sprcount)
	{
		ft_aftersort(dat, i);
		ft_drawsprite(dat);
		i++;
	}
}

void	ft_sortsprites(t_datos *dat)
{
	int i;

	i = 0;
	while (i < dat->sprcount)
	{
		dat->spr_ord[i] = i;
		dat->spr_dist[i] = ((dat->rct->plposx - dat->sprarray[i][0])
			* (dat->rct->plposx - dat->sprarray[i][0])
				+ (dat->rct->plposy - dat->sprarray[i][1])
					* (dat->rct->plposy - dat->sprarray[i][1]));
		i++;
	}
	ft_sortsprites2(dat);
}

void	ft_sortsprites2(t_datos *dat)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < dat->sprcount)
	{
		j = i + 1;
		while (j < dat->sprcount)
		{
			if (dat->spr_dist[dat->spr_ord[i]] < dat->spr_dist[dat->spr_ord[j]])
			{
				temp = dat->spr_ord[i];
				dat->spr_ord[i] = dat->spr_ord[j];
				dat->spr_ord[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_aftersort(t_datos *dat, int i)
{
	dat->spritex = (double)dat->sprarray[dat->spr_ord[i]][0]
		- (dat->rct->plposx - 0.5);
	dat->spritey = (double)dat->sprarray[dat->spr_ord[i]][1]
		- (dat->rct->plposy - 0.5);
	dat->invdet = 1.0 / (dat->rct->planex * dat->rct->diry
		- dat->rct->dirx * dat->rct->planey);
	dat->transformx = dat->invdet *
		(dat->rct->diry * dat->spritex - dat->rct->dirx * dat->spritey);
	dat->transformy = dat->invdet *
		(-dat->rct->planey * dat->spritex + dat->rct->planex * dat->spritey);
	dat->spritescreenx = (int)((dat->r1 / 2) *
		(1 + dat->transformx / dat->transformy));
	dat->spriteheight = abs((int)(dat->r2 / (dat->transformy)));
	dat->drawstarty = -dat->spriteheight / 2 + dat->r2 / 2;
	dat->drawstarty < 0 ? dat->drawstarty = 0 : dat->drawstarty;
	dat->drawendy = dat->spriteheight / 2 + dat->r2 / 2;
	if (dat->drawendy >= dat->r2)
		dat->drawendy = dat->r2 - 1;
	dat->spritewidth = abs((int)(dat->r1 / (dat->transformy)));
	dat->drawstartx = -dat->spritewidth / 2 + dat->spritescreenx;
	if (dat->drawstartx < 0)
		dat->drawstartx = 0;
	dat->drawendx = dat->spritewidth / 2 + dat->spritescreenx;
	if (dat->drawendx >= dat->r1)
		dat->drawendx = dat->r1 - 1;
}
