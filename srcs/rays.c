/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:11:33 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/03 12:35:30 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_rays(t_datos *dat)
{
	int x;

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
		//empezamos texturas
		//calculamos el valor de wallx
		if (dat->rct->side == 0)
			dat->wallx = dat->rct->plposy + dat->rct->perpwalldist * dat->rct->raydiry;
		else
			dat->wallx = dat->rct->plposx + dat->rct->perpwalldist * dat->rct->raydirx;
		dat->wallx -= floor(dat->wallx);
		if (dat->rct->side == 0 && dat->rct->raydirx > 0)
			dat->text = 0;
		if (dat->rct->side == 0 && dat->rct->raydirx <= 0)
			dat->text = 1;
		if (dat->rct->side == 1 && dat->rct->raydiry > 0)
			dat->text = 2;
		if (dat->rct->side == 1 && dat->rct->raydiry <= 0)
			dat->text = 3;
		//coordenada x de la textura
		dat->tex_x = (int)(dat->wallx * (double)dat->tex[dat->text].width);
		if (dat->rct->side == 0 && dat->rct->raydirx > 0)
			dat->tex_x = dat->tex[dat->text].width - dat->tex_x - 1;
		if (dat->rct->side == 1 && dat->rct->raydiry < 0)
			dat->tex_x = dat->tex[dat->text].width - dat->tex_x - 1;
		//Averiguamos cuanto tenemos que estirar la textura en la pantalla
		dat->step = 1.0 * dat->tex[dat->text].height / dat->rct->lineheight;
		//coordenada de inicio de la textura
		dat->texpos = (dat->rct->drawstart - dat->r2 / 2 + dat->rct->lineheight / 2) * dat->step;
		//sprites (creo)
		
		//Dibujar los píxeles en la línea vertical
		ft_verline(x, dat);
		//Sprites
		x++;
	}
	ft_spritesbucle(dat);
}

void	ft_verline(int x, t_datos *dat)
{
	int y;
	int floor;
	int ceiling;

	floor = ft_color(dat->f);
	ceiling = ft_color(dat->c);
	y = 0;

	dat->zbuffer[x] = dat->rct->perpwalldist;
	while (y < dat->rct->drawstart)
	{
		ft_mlx_pixel_put(dat, x, y, floor);
		y++;
	}
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
		dat->spr_dist[i] = ((dat->rct->plposx - dat->sprarray[i][0]) * (dat->rct->plposx - dat->sprarray[i][0])
			+ (dat->rct->plposy - dat->sprarray[i][1]) * (dat->rct->plposy - dat->sprarray[i][1]));
			i++;
	}
	ft_sortsprites2(dat);
}

void	ft_sortsprites2(t_datos *dat)
{
	    int     i;
    int     j;
    int     temp;

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
	//proyección y dibujado

		//transladar la posicion relativa del sprite a la cámara 
		dat->spritex = (double)dat->sprarray[dat->spr_ord[i]][0] - (dat->rct->plposx - 0.5);
		dat->spritey = (double)dat->sprarray[dat->spr_ord[i]][1] - (dat->rct->plposy - 0.5);
		//transformar el sprite con la camara de la matriz inversa
		dat->invdet = 1.0 / (dat->rct->planex * dat->rct->diry - dat->rct->dirx * dat->rct->planey);
		dat->transformx = dat->invdet * (dat->rct->diry * dat->spritex - dat->rct->dirx * dat->spritey);
		dat->transformy = dat->invdet * (-dat->rct->planey * dat->spritex + dat->rct->planex * dat->spritey);
		dat->spritescreenx = (int)((dat->r1 / 2) * (1 + dat->transformx / dat->transformy));
		//calculamos el alto del sprite en la pantalla
		dat->spriteheight = abs((int)(dat->r2 / (dat->transformy)));
		//calculamos el pixel mas alto y mas bajo para rellenar
		dat->drawstarty = -dat->spriteheight / 2 + dat->r2 / 2;
		if (dat->drawstarty < 0)
			dat->drawstarty = 0;
		dat->drawendy = dat->spriteheight / 2 + dat->r2 / 2;
		if (dat->drawendy >= dat->r2)
			dat->drawendy = dat->r2 - 1;
		//calculamos el ancho del sprite
		dat->spritewidth = abs((int)(dat->r1 / (dat->transformy)));
		dat->drawstartx = -dat->spritewidth / 2 + dat->spritescreenx;
		if (dat->drawstartx < 0)
			dat->drawstartx = 0;
		dat->drawendx = dat->spritewidth / 2 + dat->spritescreenx;
		if (dat->drawendx >= dat->r1)
			dat->drawendx = dat->r1 - 1;
		//loop para cada linea vertical
}
void	ft_drawsprite(t_datos *dat)
{
	int stripe;
	int tex_x;
	int y;
	int d;
	int tex_y;
	unsigned int color;
	
	stripe = dat->drawstartx;
	while (stripe < dat->drawendx)
	{
		tex_x = (int)(256 * (stripe - (-dat->spritewidth / 2 + dat->spritescreenx))
			* dat->tex->width / dat->spritewidth) / 256;
		y = dat->drawstarty;
		if (dat->transformy > 0 && stripe > 0 && stripe < dat->r1 && dat->transformy < dat->zbuffer[stripe])
			while (y < dat->drawendy)
			{
				d = (y) * 256 - dat->r2 * 128 + dat->spriteheight * 128;
				tex_y = ((d * dat->tex->height) / dat->spriteheight) / 256;
				color = ft_pixel_get2(dat, tex_x, tex_y);
				if ((color & 0x00FFFFFF) != 0)
					ft_mlx_pixel_put(dat, stripe, y, ft_pixel_get2(dat, tex_x, tex_y));
				y++;
			}
		stripe++;
	}
}