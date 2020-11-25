/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preraycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:58:03 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/25 12:16:18 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_preraycasting(t_datos *dat)
{
	ft_intmap(dat);
	ft_configadd(dat);
}

void	ft_intmap(t_datos *dat)
{
	int x;
	int y;
	int l;

	x = 0;
	dat->mapint = ft_calloc(sizeof(int *), (dat->filmap));
	while (dat->mapa[x] != '\0')
	{
		l = (ft_strlen(dat->mapa[x]));
		dat->mapint[x] = ft_calloc(sizeof(int), l);
		y = 0;
		while (dat->mapa[x][y] != '\0')
		{
			dat->mapint[x][y] = dat->mapa[x][y];
			y++;
		}
		dat->mapint[x][y] = 0;
		x++;
	}
	// imprimir mapa solo comprobación
	/*x = 0;
	y = 0;
	while (dat->mapint[x])
	{
		while (dat->mapint[x][y])
		{
			printf("%i ", (dat->mapint[x][y]));
			y++;
		}
		printf("\n");
		x++;
		y = 0;
	}*/
}

void	ft_configadd(t_datos *dat)
{
	char **aux;
	aux = ft_split(dat->r, ' ');
	dat->r1 = ft_atoi(aux[1]);
	dat->r2 = ft_atoi(aux[2]);
	dat->bits_per_pixel = 4;
	dat->endian = 0;
	dat->line_length = dat->r1;
	free(aux);
}