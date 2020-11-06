/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:22:39 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/06 13:41:04 by cnavarro         ###   ########.fr       */
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
				perror("Error\nCaracteres en mapa no validos");
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

	ft_quitaespacios2000(f);
	aux1 = ft_split(f, ' ');
	aux2 = ft_split(aux1[1], ',');
	ft_freematrix(aux1);
	ft_focnumerico(aux2);
	ft_focmaximo(aux2);
	ft_freematrix(aux2);
}

void	ft_errortexture(char *texture)
{
	int i;
	int fd;
	char *aux;

	i = ft_strlen(texture);
	i--;
	if (!(texture[i - 4]) || (texture[i - 3]) != '.' || (texture[i - 2]) != 'x' || 
		(texture[i - 1]) != 'p' || (texture[i]) != 'm')
		{
			perror("Error\nTextura no valida");
			exit(3);
		}
	aux = ft_convtexture(texture);
	if (!((fd = open(aux, O_RDONLY) > 0)))
	{
		perror("Error\nNo se ha podido abrir la textura");
		exit(11);
	}
	free(aux);
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
		perror("Error\nArgumentos en R incorrectos");
		exit(4);
	}
	ft_rnumerico(aux);
	ft_freematrix(aux);
}
