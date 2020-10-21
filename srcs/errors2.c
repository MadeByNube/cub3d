/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:31:21 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/20 13:52:35 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_errorextmap(t_datos *dat)
{
	char	*aux;
	int		i;

	aux = ft_strdup(dat->mapname);
	i = ft_strlen(aux);
	i--;
	if (!(aux[i - 4]) || (aux[i - 3]) != '.' || (aux[i - 2]) != 'c' ||
		(aux[i - 1]) != 'u' || (aux[i]) != 'b')
		perror("Textura no válida");
}

void	ft_valmap(char **mapa, t_datos *dat)
{
	int	x;
	int	y;
	int	a;
	int	b;
	int	cont;

	a = 0;
	b = 0;
	cont = 0;
	while (mapa[a])
	{
		while (mapa[a][b])
		{
			if (mapa[a][b] == 'N' || mapa[a][b] == 'S' ||
				mapa[a][b] == 'E' || mapa[a][b] == 'W')
			{
				x = a;
				y = b;
				cont++;
			}
		}
	}
	if (cont != 1)
	{
		perror("Error: Hay más de una posición de jugador");
		return ;
	}
	ft_valmap2(mapa, x, y, dat);
}

void	ft_valmap2(char **mapa, int x, int y, t_datos *dat)
{
	if (x == 0 || y == 0 || y == ft_strlen(mapa[x]) || x == dat->filmap - 1)
	{
		perror("Error: mapa abierto");
		return ;
	}

	if (mapa[x][y + 1] == 0 || mapa[x][y + 1] == 2)
	{
		mapa[x][y + 1] = 3;
		ft_valmap2(mapa, x, y + 1, dat);
	}
	if (mapa[x][y - 1] == 0 || mapa[x][y - 1] == 2)
	{
		mapa[x][y - 1] = 3;
		ft_valmap2(mapa, x, y - 1, dat);
	}
	if (mapa[x + 1][y] == 0 || mapa[x + 1][y] == 2)
	{
		mapa[x + 1][y] = 3;
		ft_valmap2(mapa, x + 1, y, dat);
	}
	if (mapa[x - 1][y] == 0 || mapa[x - 1][y] == 2)
	{
		mapa[x - 1][y] = 3;
		ft_valmap2(mapa, x - 1, y, dat);
	}
}