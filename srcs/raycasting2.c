/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:48:29 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/27 13:56:31 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_player(t_datos *dat, int posx, int posy, int tam)
{
	int x;
	int y;

	x = posx;
	y = posy;
	while (y <= posy + tam)
	{
		while (x <= posx + tam)
		{
			ft_mlx_pixel_put(dat, x, y, 0x00FF00);
			x++;
		}
		x = posx;
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
		printf("Iquierda\n");
	else if (keycode == KEY_D)
		printf("Derecha\n");
	else if (keycode == KEY_W)
		printf("Arriba\n");
	else if (keycode == KEY_S)
		printf("Abajo\n");
	else
		printf("Otra\n");
}
