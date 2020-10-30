/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavarro <cnavarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:23:53 by cnavarro          #+#    #+#             */
/*   Updated: 2020/10/30 14:27:59 by cnavarro         ###   ########.fr       */
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
				perror("Error: Argumento de R no es numérico");
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

	while((comp = getnextline(&line, fdmap)) > 0)
	{
		if (line[0] == 'R' && line[1] == ' ')
			ft_saveorerror_r(dat, line);
		else if (line[0] == 'N' && line[1] == 'O')
			ft_saveorerror_no(dat, line);
		else if (line[0] == 'S' && line[1] == 'O')
			ft_saveorerror_no(dat, line);
		else if (line[0] == 'W' && line[1] == 'E')
			ft_saveorerror_no(dat, line);
		else if (line[0] == 'E' && line[1] == 'A')
			ft_saveorerror_no(dat, line);
		else if (line[0] == 'S' && line[1] == ' ')
			ft_saveorerror_no(dat, line);
		else if (line[0] == 'F' && line[1] == ' ')
			ft_saveorerror_no(dat, line);
		else if (line[0] == 'C' && line[1] == ' ')
			ft_saveorerror_no(dat, line);
		else if (line[0] == '\n');
		else break;
		dat->nomaplines++;
		free(line);
	}
	free(line);
}