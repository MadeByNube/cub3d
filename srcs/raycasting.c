/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:52:12 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/04 11:40:50 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_raycasting(t_datos *dat)
{
	dat->mlx_ptr = mlx_init();
	//ft_texturas(dat);
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, dat->r1, dat->r2, "cub3D");
	//printf("hola2\n%i\n%i\n%i\n", dat->bits_per_pixel, dat->line_length, dat->endian);
	mlx_loop_hook(dat->mlx_ptr, ft_main_loop, dat);
	mlx_key_hook(dat->win_ptr, key_hook, dat);
	mlx_loop(dat->mlx_ptr);
}

void	ft_mlx_pixel_put(t_datos *dat, int x, int y, int color)
{
	char *aux;

	aux = dat->dir + (y * dat->line_length + x * (dat->bits_per_pixel / 8));
	*(unsigned int*)aux = color;
}

void	ft_floor_and_sky(t_datos *dat)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < (dat->r2))
	{
		while (x < dat->r1)
		{
			if	(y < (dat->r2 / 2))
				ft_mlx_pixel_put(dat, x, y, ft_color(dat->f));
			else
				ft_mlx_pixel_put(dat, x, y, ft_color(dat->c));
			x++;
		}
		x = 0;
		y++;
	}
}
