/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:52:12 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/25 12:57:31 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"


void	ft_raycasting(t_datos *dat)
{
	ft_preraycasting(dat);
	ft_openwindow(dat);
}

void	ft_mlx_pixel_put(t_datos *dat, int x, int y, int color)
{
	char *aux;

	aux = dat->dir + (y * dat->line_length + x * (dat->bits_per_pixel / 8));
	*(unsigned int*)aux = color;
}

void	ft_openwindow(t_datos *dat)
{
	dat->mlx_ptr = mlx_init();
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, dat->r1, dat->r2, "window");
	dat->img = mlx_new_image(dat->mlx_ptr, dat->r1, dat->r2);
	dat->dir =mlx_get_data_addr(dat->img, &dat->bits_per_pixel, &dat->line_length, &dat->endian); //endian es el orden de lectura de los bytes(lo hemmos puesto como 0, de momento)
	ft_floor_and_sky(dat);
	mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr, dat->img, 0, 0);
	mlx_loop(dat->mlx_ptr);
}

void	ft_floor_and_sky(t_datos *dat)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < (dat->r2 / 2))
	{
		while (x < dat->r1)
		{
			ft_mlx_pixel_put(dat, x, y, 0x0000FF);
			x++;
		}
		x = 0;
		y++;
	}
	while (y < (dat->r2))
	{
		while (x < dat->r1)
		{
			ft_mlx_pixel_put(dat, x, y, 0xFF0000);
			x++;
		}
		x = 0;
		y++;
	}
}