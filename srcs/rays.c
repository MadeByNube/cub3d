/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:11:33 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/15 13:35:43 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_rays(t_datos *dat)
{
	double x;

	x = 0;
//Recorro las columnas. Hay tantas columnas como ancho hay en la resolución (dat->r1)
	while (x < dat->r1)
	{
		//calculamos posición del rayo y dirección
		dat->rct->camx = 2 * x / (double)(dat->r1) - 1;
		dat->rct->raydirx = dat->rct->dirx + dat->rct->planex * dat->rct->camx;
		dat->rct->raydiry = dat->rct->diry + dat->rct->planey * dat->rct->camx;
		//cuadrado en el que nos encontramos:
		dat->rct->mapx = (int)dat->rct->plposx;
		dat->rct->mapy = (int)dat->rct->plposy;
		//tamaño del rayo desde xside o yside hasta el próximo xside o yside "Alternativa porque C no divide entre 0"
		/*dat->rct->deltadistx = (dat->rct->raydiry == 0) ? 0 : ((dat->rct->raydirx == 0) ? 1 : fabs(1 / dat->rct->raydirx));
		dat->rct->deltadisty = (dat->rct->raydirx == 0) ? 0 : ((dat->rct->raydiry == 0) ? 1 : fabs(1 / dat->rct->raydiry));*/
		dat->rct->deltadistx = fabs(1 / dat->rct->raydirx);
		dat->rct->deltadisty = fabs(1 / dat->rct->raydiry);
		//Hay wall hit?
		dat->rct->hit = 0;
		//calculamos step y sidedist inicial
		if (dat->rct->raydirx < 0)
		{
			dat->rct->stepx = -1;
			dat->rct->sidedistx = (dat->rct->plposx - dat->rct->mapx) * dat->rct->deltadistx;
		}
		else
		{
			dat->rct->stepx = 1;
			dat->rct->sidedistx = (dat->rct->mapx + 1.0 - dat->rct->plposx) * dat->rct->deltadistx;
		}
		if (dat->rct->raydiry < 0)
		{
			dat->rct->stepy = -1;
			dat->rct->sidedisty = (dat->rct->plposy - dat->rct->mapy) * dat->rct->deltadisty;
		}
		else
		{
			dat->rct->stepy = 1;
			dat->rct->sidedisty = (dat->rct->mapy + 1.0 - dat->rct->plposy) * dat->rct->deltadisty;
		}
		//DDA "Consiste en recorrer un rayo parandose en los bordes de las cuadrículas"
		while (dat->rct->hit == 0)
		{
			//Saltar al siguiente cuadrado
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
			//Checkeamos si el rayo golpea el muro
			if (dat->mapint[dat->rct->mapx][dat->rct->mapy] > 0)
				dat->rct->hit = 1;
		}
		//Calculamos la distancia proyectada en la direccion de la camara (con distancia euclidea habrá efecto ojo de pez)
		if (dat->rct->side == 0)
			dat->rct->perpwalldist = (dat->rct->mapx - dat->rct->plposx + (1 - dat->rct->stepx) / 2) / dat->rct->raydirx;
		else
			dat->rct->perpwalldist = (dat->rct->mapy - dat->rct->plposy + (1 - dat->rct->stepy) / 2) / dat->rct->raydiry;
		//Calculamos el tamaño de la linea dibujada en la pantalla
		dat->rct->lineheight = (int)(dat->r2 / dat->rct->perpwalldist);
		//Calculamos el pixel mas bajo y mas alto para rellenar la actual "raya"
		dat->rct->drawstart = -dat->rct->lineheight / 2 + dat->r2 / 2;
		if (dat->rct->drawstart < 0)
			dat->rct->drawstart = 0;
		dat->rct->drawend = dat->rct->lineheight / 2 + dat->r2 / 2;
		if (dat->rct->drawend >= dat->r2)
			dat->rct->drawend = dat->r2 - 1;
		//Dibujar los píxeles en la línea vertical
		ft_verline(x, dat);
		x++;
	}	
}

void	ft_verline(int x, t_datos *dat)
{
	int y;
	int floor;
	int ceiling;

	floor = ft_color(dat->f);
	ceiling = ft_color(dat->c);
	y = 0;

	while (y < dat->rct->drawstart)
	{
		ft_mlx_pixel_put(dat, x, y, floor);
		y++;
	}
	while (y < dat->rct->drawend)
	{
		ft_mlx_pixel_put(dat, x, y, 1022783);
		y++;
	}
	while (y < dat->r2)
	{
		ft_mlx_pixel_put(dat, x, y, ceiling);
		y++;
	}
	
}
