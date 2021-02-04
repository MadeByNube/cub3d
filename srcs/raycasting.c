/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:52:12 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/04 13:40:15 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_raycasting(t_datos *dat)
{

	dat->mlx_ptr = mlx_init();
	ft_texturas(dat);
	if (dat->save == 1)
		ft_main_loop(dat);
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, dat->r1, dat->r2, "cub3D");
	mlx_hook(dat->win_ptr, 17, 1L << 17, ft_exit, dat);
	mlx_hook(dat->win_ptr, 2, 1L << 0, ft_keypress, dat);
	mlx_hook(dat->win_ptr, 3, 1L << 1, ft_keyrelease, dat);
	mlx_loop_hook(dat->mlx_ptr, ft_main_loop, dat);
	mlx_loop(dat->mlx_ptr);
}

void	ft_mlx_pixel_put(t_datos *dat, int x, int y, int color)
{
	char *aux;

	aux = dat->dir + (y * dat->line_length + x * (dat->bits_per_pixel / 8));
	*(unsigned int*)aux = color;
}

int		ft_pixel_get(t_datos *dat, int x, int y)
{
	char *aux;
	
	aux = dat->tex[dat->text].addr + (y * dat->tex[dat->text].size + x * (dat->tex[dat->text].bpp / 8));
	return (*(unsigned int*)aux);
}
int		ft_pixel_get2(t_datos *dat, int x, int y)
{
	char *aux;
	
	aux = dat->tex[4].addr + (y * dat->tex[4].size + x * (dat->tex[4].bpp / 8));
	return (*(unsigned int*)aux);
}
