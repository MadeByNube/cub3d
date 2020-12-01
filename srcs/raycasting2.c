/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:48:29 by cnavarro          #+#    #+#             */
/*   Updated: 2020/12/01 14:35:00 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_player(t_datos *dat, int tam)
{
	int x;
	int y;

	x = dat->posx;
	y = dat->posy;
	while (y <= dat->posy + tam)
	{
		while (x <= dat->posx + tam)
		{
			ft_mlx_pixel_put(dat, x, y, 0x00FF00);
			x++;
		}
		x = dat->posx;
		y++;
	}
}

int		ft_color(char *cadena)
{
	char **aux;
	char **colores;
	int color;

	aux = ft_split(cadena, ' ');
	colores = ft_split(aux[1], ',');
	color = (ft_atoi(colores[0]) * 256 * 256 + ft_atoi(colores[1]) * 256 + ft_atoi(colores[2]));
	return (color);
}

int		key_hook(int keycode, t_datos *dat)
{
	if (keycode == KEY_A)
		dat->posx -= 10;
	else if (keycode == KEY_D)
		dat->posx += 10;
	else if (keycode == KEY_W)
		dat->posy -= 10;
	else if (keycode == KEY_S)
		dat->posy += 10;
	else if (keycode == KEY_ESCAPE)
	{
		//mlx_destroy_window(dat->mlx_ptr, dat->win_ptr); Da segmentation fault
		exit(16);
	}
	else
		printf("Otra\n");
	return (0);
}
