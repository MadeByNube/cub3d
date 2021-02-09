/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:49:33 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/08 13:02:16 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_drawsprite(t_datos *dat)
{
	int				tex_x;
	int				y;
	int				d;
	int				tex_y;
	unsigned int	color;

	dat->stripe = dat->drawstartx;
	while (dat->stripe < dat->drawendx)
	{
		tex_x = (int)(256 * (dat->stripe - (-dat->spritewidth / 2
		+ dat->spritescreenx)) * dat->tex->width / dat->spritewidth) / 256;
		y = dat->drawstarty - 1;
		if (dat->transformy > 0 && dat->stripe > 0 && dat->stripe < dat->r1 &&
			dat->transformy < dat->zbuffer[dat->stripe])
			while (++y < dat->drawendy)
			{
				d = (y) * 256 - dat->r2 * 128 + dat->spriteheight * 128;
				tex_y = ((d * dat->tex->height) / dat->spriteheight) / 256;
				color = *(unsigned int *)(dat->tex[4].addr +
					(tex_y * dat->tex[4].size + tex_x * (dat->tex[4].bpp / 8)));
				if ((color & 0x00FFFFFF) != 0)
					ft_mlx_pixel_put(dat, dat->stripe, y, color);
			}
		dat->stripe++;
	}
}
