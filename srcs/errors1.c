/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:22:39 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/30 10:14:21 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_charsmap(char **mapa)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (mapa[x])
	{
		while (mapa[x][y])
		{
			if (!(mapa[x][y] == '0' || mapa[x][y] == '1' || mapa[x][y] == '2' || mapa[x][y] == ' '
				|| mapa[x][y] == 'S' || mapa[x][y] == 'W' || mapa[x][y] == 'E' || mapa[x][y] == 'N'))
			{
				perror("Error: Caracteres en mapa no validos");
				exit(1);
			}
			y++;
		}
		y = 0;
		x++;		
	}
}

void	ft_erroresgeneral(t_datos *dat)
{
	ft_errorextmap(dat);
}

void	ft_errorfoc(char *f)
{
	char 	**aux1;
	char 	**aux2;
	int		x;
	int		y;

	aux1 = ft_split(f, ' ');
	aux2 = ft_split(aux1[1], ',');
	ft_freematrix(aux1);
	x = 0;
	y = 0;
	while(aux2[x])
	{
		while (aux2[x][y])
		{
			if (!ft_isdigit(aux2[x][y]))
			{
				perror("Error: Argumento de R no es numerico");
				exit(2);
			}
			y++;
		}
		y = 0;
		x++;
	}
	ft_freematrix(aux2);
}

void	ft_errortexture(char *texture)
{
	int i;

	i = ft_strlen(texture);
	i--;
	if (!(texture[i-4]) || (texture[i-3]) != '.' || (texture[i-2]) != 'x' || 
		(texture[i-1]) != 'p' || (texture[i]) != 'm')
		{
			perror("Textura no válida");
			exit(3);
		}
}

void	ft_errorerre(char *r)
{
	char **aux;
	int x;
	int y;

	x = 0;
	y = 0;
	aux = ft_split(r, ' ');
	while (aux[x])
		x++;
	if (x != 3)
	{
		perror("Error: Argumentos en R incorrectos");
		exit(4);
	}
	x = 1;
	while(aux[x])
	{
		while (aux[x][y])
		{
			if (!ft_isdigit(aux[x][y]))
			{
				perror("Error: Argumento de R no es numérico");
				exit(EXIT_FAILURE);
			}
			y++;
		}
		y = 0;
		x++;
	}
	x = 0;
	ft_freematrix(aux);
}
