/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:31:21 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/30 13:38:29 by cnavarro         ###   ########.fr       */
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
			perror("Textura no válida");
			exit(5);
		}
	free(aux);
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
			b++;
		}
		b = 0;
		a++;
	}
	if (cont != 1)
	{
		perror("Error: Hay 0 o mas de 1 posicion de jugador");
		exit(6);
	}
	ft_valmap2(mapa, x, y, dat);
}

void	ft_valmap2(char **mapa, int x, int y, t_datos *dat)
{
	if (x == 0 || y == 0 || y == ft_strlen(mapa[x]) || x == dat->filmap - 1 ||
		y > ft_strlen(mapa[x + 1]) || y > ft_strlen(mapa[x - 1]))
	{
		perror("Error: mapa abierto");
		exit(7);
	}
	mapa[x][y] = '3';
	if (mapa[x][y + 1] == '0' || mapa[x][y + 1] == '2' || mapa[x][y + 1] == ' ')
		ft_valmap2(mapa, x, y + 1, dat);
	if (mapa[x][y - 1] == '0' || mapa[x][y - 1] == '2' || mapa[x][y + 1] == ' ')
		ft_valmap2(mapa, x, y - 1, dat);
	if (mapa[x + 1][y] == '0' || mapa[x + 1][y] == '2' || mapa[x][y + 1] == ' ')
		ft_valmap2(mapa, x + 1, y, dat);
	if (mapa[x - 1][y] == '0' || mapa[x - 1][y] == '2' || mapa[x][y + 1] == ' ')
		ft_valmap2(mapa, x - 1, y, dat);
}
void	ft_focnumerico(char **aux2)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while(aux2[x])
	{
		while (aux2[x][y])
		{
			if (!ft_isdigit(aux2[x][y]))
			{
				perror("Error: Valores no numericos");
				exit(2);
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (x != 3)
	{
		perror("Error: Color debe tener 3 valores");
		exit(10);
	}
}
void	ft_focmaximo(char **aux2)
{
	int	x;

	x = 0;
	while(aux2[x])
	{
		if (ft_atoi(aux2[x]) < 0 || ft_atoi(aux2[x]) > 255)
		{
			perror("Error: color incorrecto");
		}
		x++;
	}
}