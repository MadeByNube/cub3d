/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:31:21 by cnavarro          #+#    #+#             */
/*   Updated: 2021/02/05 13:44:01 by cnavarro         ###   ########.fr       */
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
	{
		perror("Error\nExtension de mapa invalida");
		exit(5);
	}
	free(aux);
}

void	ft_perrorvalmap(void)
{
	perror("Error\nHay 0 o mas de 1 posicion de jugador");
	exit(6);
}

void	ft_valmap(char **mapa, t_datos *dat)
{
	int a[3];

	a[0] = -1;
	a[2] = 0;
	while (mapa[++a[0]])
	{
		a[1] = -1;
		while (mapa[a[0]][++a[1]])
		{
			if (mapa[a[0]][a[1]] == 'N' || mapa[a[0]][a[1]] == 'S' ||
				mapa[a[0]][a[1]] == 'E' || mapa[a[0]][a[1]] == 'W')
			{
				dat->cardinal = mapa[a[0]][a[1]];
				dat->rct->plposx = a[0];
				dat->rct->plposy = a[1];
				a[2]++;
			}
		}
	}
	if (a[2] != 1)
		ft_perrorvalmap();
	ft_valmap2(mapa, dat->rct->plposx, dat->rct->plposy, dat);
	dat->rct->plposx += 0.5;
	dat->rct->plposy += 0.5;
}

void	ft_valmap2(char **mapa, int x, int y, t_datos *dat)
{
	if (x == 0 || y == 0 || y == (ft_strlen(mapa[x]) - 1) ||
		x == dat->filmap - 1 || y > ft_strlen(mapa[x + 1]) ||
			y > ft_strlen(mapa[x - 1]))
	{
		perror("Error\nMapa abierto");
		exit(7);
	}
	mapa[x][y] = '3';
	if (mapa[x][y + 1] == '0' || mapa[x][y + 1] == '2' || mapa[x][y + 1] == ' ')
		ft_valmap2(mapa, x, y + 1, dat);
	if (mapa[x][y - 1] == '0' || mapa[x][y - 1] == '2' || mapa[x][y - 1] == ' ')
		ft_valmap2(mapa, x, y - 1, dat);
	if (mapa[x + 1][y] == '0' || mapa[x + 1][y] == '2' || mapa[x + 1][y] == ' ')
		ft_valmap2(mapa, x + 1, y, dat);
	if (mapa[x - 1][y] == '0' || mapa[x - 1][y] == '2' || mapa[x - 1][y] == ' ')
		ft_valmap2(mapa, x - 1, y, dat);
}

void	ft_focnumerico(char **aux2)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (aux2[x])
	{
		while (aux2[x][y])
		{
			if (!ft_isdigit(aux2[x][y]))
			{
				perror("Error\nF o C con Valores no numericos o negativos");
				exit(2);
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (x != 3)
	{
		perror("Error\nColor debe tener 3 valores");
		exit(10);
	}
}
