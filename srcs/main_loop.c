/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:49:33 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/03 12:08:17 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	ft_main_loop(t_datos *dat)
{
	dat->img = mlx_new_image(dat->mlx_ptr, dat->r1, dat->r2);
	dat->dir = mlx_get_data_addr(dat->img, &dat->bits_per_pixel, &dat->line_length, &dat->endian); //endian es el orden de lectura de los bytes(lo hemmos puesto como 0, de momento)
	key_hook(dat);
	ft_rays(dat);
	mlx_put_image_to_window(dat->mlx_ptr, dat->win_ptr, dat->img, 0, 0);
	mlx_destroy_image(dat->mlx_ptr, dat->img);
	return (0);
}
