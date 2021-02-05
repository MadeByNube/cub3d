/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preraycasting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:58:03 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/05 12:53:11 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		ft_keyrelease(int key, t_datos *dat)
{
	if (key == KEY_W)
		dat->keyw = 0;
	if (key == KEY_S)
		dat->keys = 0;
	if (key == KEY_D)
		dat->keyd = 0;
	if (key == KEY_A)
		dat->keya = 0;
	if (key == KEY_LEFT)
		dat->left = 0;
	if (key == KEY_RIGHT)
		dat->right = 0;
	return (0);
}

int		ft_exit(t_datos *dat)
{
	mlx_destroy_window(dat->mlx_ptr, dat->win_ptr);
	dat->mlx_ptr = NULL;
	free(dat->mlx_ptr);
	exit(19);
	return (0);
}

void	ft_presprites(t_datos *dat)
{
	int i;

	i = 0;
	dat->sprcount = ft_count2(dat);
	dat->sprarray = ft_calloc(sizeof(int *), dat->sprcount);
	while (i < dat->sprcount)
	{
		dat->sprarray[i] = ft_calloc(sizeof(int), 2);
		i++;
	}
	ft_arraylogs(dat);
	dat->spr_ord = ft_calloc(sizeof(int), dat->sprcount);
	dat->spr_dist = ft_calloc(sizeof(double), dat->sprcount);
}

int		ft_count2(t_datos *dat)
{
	int count;
	int x;
	int y;

	x = 0;
	y = 0;
	count = 0;
	while (dat->mapa[x])
	{
		while (dat->mapa[x][y])
		{
			if (dat->mapa[x][y] == '2')
				count++;
			y++;
		}
		y = 0;
		x++;
	}
	return (count);
}

void	ft_arraylogs(t_datos *dat)
{
	int x;
	int y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while (dat->mapa[x])
	{
		while (dat->mapa[x][y])
		{
			if (dat->mapa[x][y] == '2')
			{
				dat->sprarray[count][0] = x;
				dat->sprarray[count][1] = y;
				count++;
			}
			y++;
		}
		x++;
		y = 0;
	}
}
