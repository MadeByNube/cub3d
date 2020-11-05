/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:23:53 by cnavarro          #+#    #+#             */
/*   Updated: 2020/11/05 12:59:36 by cnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_rnumerico(char **aux)
{
	int x;
	int y;

	x = 1;
	y = 0;
	while(aux[x])
	{
		while (aux[x][y])
		{
			if (!ft_isdigit(aux[x][y]))
			{
				perror("Error\nArgumento de R no es numerico");
				exit(EXIT_FAILURE);
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_saveconfig(int fdmap, t_datos *dat)
{
	char *line;
	int comp;
	int i;

	while((comp = getnextline(&line, fdmap)) > 0)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == 'R' && line[i + 1] == ' ')
			ft_saveorerror_r(dat, line);
		else if (line[i] == 'N' && line[i + 1] == 'O')
			ft_saveorerror_no(dat, line);
		else if (line[i] == 'S' && line[i + 1] == 'O')
			ft_saveorerror_so(dat, line);
		else if (line[i] == 'W' && line[i + 1] == 'E')
			ft_saveorerror_we(dat, line);
		else if (line[i] == 'E' && line[i + 1] == 'A')
			ft_saveorerror_ea(dat, line);
		else if (line[i] == 'S' && line[i + 1] == ' ')
			ft_saveorerror_s(dat, line);
		else if (line[i] == 'F' && line[i + 1] == ' ')
			ft_saveorerror_f(dat, line);
		else if (line[i] == 'C' && line[i + 1] == ' ')
			ft_saveorerror_c(dat, line);
		else if (line[i] == '\n');
		else break;
		dat->nomaplines++;
		free(line);
	}
	free(line);
}

void	ft_correctconfig(t_datos *dat)
{
	if (!dat->r || !dat->no || !dat->so || !dat->we || !dat->ea || !dat->s || !dat->f || !dat->c)
	{
		perror("Error\nConfiguracion incompleta");
	}
}
void	ft_quitaespacios2000(char *f)
{
	int i;
	int pos;
	char *aux;

	aux = malloc(sizeof(char *) * ft_strlen(f));
	pos = 0;
	i = 0;
	while (f[pos] == ' ')
		pos++;
	aux[i++] = f[pos++];
	aux[i++] = f[pos++];
	while (f[pos])
	{
		if (f[pos] == ' ')
			pos++;
		else
			aux[i++] = f[pos++];
	}
}